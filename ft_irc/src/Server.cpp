#include "../headers/Server.hpp"

bool g_terminateRequested = false;

Server::Server(const std::string &ip, int port, std::string pass) {
	_ip = ip;
	_port = port;
	_pass = pass;
	_num_fds = 0;
	_num_users = 0;
}

Server::~Server() {}

Server::Server(const Server &rhs) { *this = rhs; }

Server &Server::operator=(const Server &rhs) { (void)rhs; return *this; }

std::string	Server::getIp() const { return _ip; }

std::string	Server::getPass() const { return _pass; }

int	Server::getPort() const { return _port; }

int	Server::exitError(const std::string &str) {
	//close(_fds);
	std::cerr << str << std::endl;
	for (int i = 0; i < _num_fds; i++)
		if (_fds[i].fd >= 0)
			close(_fds[i].fd);

	//delete _clients;
	while (!_clients.empty()) {
		delete _clients.back();
		_clients.pop_back();
	}

	exit(EXIT_FAILURE);
}

int	Server::exitSuccess() {
	//close(_fds);
	for (int i = 0; i < _num_fds; i++)
		if (_fds[i].fd >= 0)
			close(_fds[i].fd);

	//delete _clients;
	while (!_clients.empty()) {
		delete _clients.back();
		_clients.pop_back();
	}

	exit(EXIT_SUCCESS);
}

void	Server::run() {
	struct sockaddr_in	address;

	//create socket
	_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_fd < 0)
		exitError("Error creating socket");

	//set socket to be non blocking
	if (fcntl(_fd, F_SETFL, O_NONBLOCK) < 0)
		exitError("Failed to set socket non-blocking mode");

	//set socket options
	int	opt = 1;
	if (setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof opt) < 0)
		exitError("Failed to set socket options");

	memset(&address, 0, sizeof address);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr(_ip.c_str());
	address.sin_port = htons(_port);

	//bind socket
	if (bind(_fd, (struct sockaddr*)&address, sizeof address) < 0)
		exitError("Error while binding socket");

	//listen
	if (listen(_fd, 10) < 0)
		exitError("Error while listening");
	
	waitForSignal();
}

void	Server::waitForSignal() {
	_num_fds = 1;

	//set listening socket to poll
	memset(_fds, 0, sizeof _fds);
	_fds[0].fd = _fd;
	_fds[0].events = POLLIN;

	//wait for client signal
	while (g_terminateRequested == false) {
		if (poll(_fds, _num_fds, -1) < 0) {
			if (g_terminateRequested == true)
				break;
			exitError("Error while polling");
		}

		for (int i = 0; i < _num_fds; i++) {
			if (_fds[i].revents & POLLIN) {
				if (_fds[i].fd == _fd) {
					//new connection
					if (acceptConnection() < 0)
						break;
				}
				else {
					//read from client
					if (readMessage(_fds[i].fd) < 0)
						break;
				}
			}
		}
	}

	exitSuccess();
}

int	Server::acceptConnection() {
	int	client_fd = -1;
	struct sockaddr_in	client_address;
	socklen_t	client_address_len = sizeof client_address;

	//accept connection
	client_fd = accept(_fd, (struct sockaddr*)&client_address, &client_address_len);
	if (client_fd < 0) {
		std::cerr << "Error while accepting connection" << std::endl;
		return -1;
	}

	//print client info
	std::cout << "New connection from " << inet_ntoa(client_address.sin_addr) << ":" << ntohs(client_address.sin_port) << std::endl;

	//set socket to be non blocking
	if (fcntl(client_fd, F_SETFL, O_NONBLOCK) < 0) {
		std::cerr << "Failed to set socket non-blocking mode" << std::endl;
		return -1;
	}

	//add client to poll
	_fds[_num_fds].fd = client_fd;
	_fds[_num_fds].events = POLLIN;
	_fds[_num_fds].revents = 0;
	_num_fds++;

	//create new client
	Client *client = new Client(client_fd, client_address, client_address_len);
	_num_users++;
	_clients.push_back(client);
	_clients.back()->setNick("user" + std::to_string(_num_users));
	_clients.back()->setUser("user" + std::to_string(_num_users));

	//send welcome message
	sendMessage(client_fd, "Welcome to the IRC server!");

	return 0;
}

int	Server::readMessage(int fd) {
	char	buf[BUFFER_SIZE];
	int		ret;
	std::string	msg;

	memset(buf, 0, BUFFER_SIZE);
	ret = recv(fd, buf, BUFFER_SIZE, 0);
	if (ret < 0 && errno != EWOULDBLOCK) {
		std::cout << "Error while reading from client" << std::endl;
		return 0;
	}
	else if (ret == 0) {
		std::cout << "Client disconnected.";
		disconnectClient(fd);
		return 0;
	}

	if (!std::strstr(buf, "\n")) {
		getClientByFd(fd)->buffer.append(buf);
		return 0;
	}
	else {
		msg.append(getClientByFd(fd)->buffer);
		msg.append(buf);
		getClientByFd(fd)->buffer.clear();
	}

	//check that message is not empty
	if (msg[msg.length() - 1] == '\n')
		msg = msg.substr(0, msg.length() - 1);
	if (msg[msg.length() - 1] == '\r')
		msg = msg.substr(0, msg.length() - 1);
	if (msg.empty())
		return 0;

	//append \0 to message
	msg += '\0';

	if (msg.substr(0, 6) == "CAP LS")
		handleIrssiMessage(fd, msg);
	else
		handleMessage(fd, msg);

	return 0;
}

void	Server::authClient(int fd, const std::string &pass) {
	if (getClientByFd(fd)->is_auth == true)
		return;
	if (strcmp(_pass.c_str(), pass.c_str()) == 0 || _pass == pass) {
		getClientByFd(fd)->is_auth = true;
		sendMessage(fd, "You are now authenticated!");
	}
	else
		sendMessage(fd, "Wrong password. Try again (send PASS <password>):");
}

void	Server::disconnectClient(int fd) {
	//remove client from all channels
	for (std::vector<Channel>::iterator it = _channels.begin(); it != _channels.end(); it++) {
		it->removeClient(getClientByFd(fd));
	}

	int	index = -1;
	//close socket
	close(fd);

	//remove client from poll
	while (++index < _num_fds)
		if (_fds[index].fd == fd) 
			break;

	if (index < _num_fds) {
		for (int i = index; i < _num_fds - 1; i++) {
			_fds[i] = _fds[i + 1];
		}
	}

	// Clean up the last element, as its content has been moved
	memset(&_fds[_num_fds - 1], 0, sizeof(struct pollfd));

	std::cout << "Connection closed from " << (getClientByFd(fd))->getIp() << ":" << (getClientByFd(fd))->getPort() << std::endl;

	//delete allocated client from list and remove client from clients list
	delete getClientByFd(fd);
	_clients.erase(std::remove(_clients.begin(), _clients.end(), getClientByFd(fd)), _clients.end());

	_num_fds--;
}

void	Server::sendMessage(int fd, std::string msg) {
	if (msg.back() == '\0')
		msg.erase(msg.length() - 1);
	msg += "\r\n";

	size_t	len = msg.length();
	while (len > 0) {
		int	ret = send(fd, msg.c_str(), len, 0);
		if (ret < 0)
			exitError("Error while writing to client");
		msg = msg.substr(ret);
		len -= ret;
	}
}

Client* Server::getClientByFd(int fd) {
	for (IT it = _clients.begin(); it != _clients.end(); it++) {
		if ((*it)->getFd() == fd)
			return *it;
	}
	return NULL;
}

void	Server::handleMessage(int fd, std::string msg) {
	std::string	command = msg.substr(0, msg.find_first_of(" "));
	std::string	params = msg.substr(msg.find_first_of(" ") + 1);
	std::string	first_param = params.substr(0, params.find_first_of(" \r\n"));

	//check if client is authenticated
	if (getClientByFd(fd)->is_auth == false) {
		if (command == "/PASS")
			authClient(fd, params);
		else
			sendMessage(fd, "You are not authenticated. Please send /PASS <password> to authenticate");
		return;
	}

	//check if message is a command
	if (command[0] == '/') {
		if (strcmp(command.c_str(), "/PASS") == 0)
			sendMessage(fd, "You are already authenticated");
		else if (strcmp(command.c_str(), "/USERS") == 0)
			sendMessage(fd, listUsers());
		else if (strcmp(command.c_str(), "/NICK") == 0)
			command == params ? sendMessage(fd, "Invalid nickname") : \
			sendMessage(fd, setNickname(fd, first_param));
		else if (strcmp(command.c_str(), "/MYNICK") == 0)
			sendMessage(fd, getClientByFd(fd)->getNick());
		else if (strcmp(command.c_str(), "/USER") == 0)
			command == params ? sendMessage(fd, "Invalid username") : \
			sendMessage(fd, getClientByFd(fd)->setUser(first_param));
		else if (strcmp(command.c_str(), "/MYUSER") == 0)
			sendMessage(fd, getClientByFd(fd)->getUser());
		else if (strcmp(command.c_str(), "/PRIVMSG") == 0)
			sendMessage(fd, sendPrivateMessage(fd, params));
		else if (strcmp(command.c_str(), "/JOIN") == 0)
			sendMessage(fd, joinChannel(fd, first_param, params.substr(params.find_first_of(" ") + 1)));
		else if (strcmp(command.c_str(), "/PART") == 0)
			sendMessage(fd, leaveChannel(fd, first_param));
		else if (strcmp(command.c_str(), "/LIST") == 0)
			sendMessage(fd, listChannels());
		else if (strcmp(command.c_str(), "/QUIT") == 0)
			disconnectClient(fd);
		else if (strcmp(command.c_str(), "/KICK") == 0)
			sendMessage(fd, kick(fd, first_param, params.substr(params.find_first_of(" ") + 1)));
		else if (strcmp(command.c_str(), "/INVITE") == 0)
			sendMessage(fd, invite(fd, params));
		else if (strcmp(command.c_str(), "/TOPIC") == 0)
			sendMessage(fd, topic(fd, params));
		else if (strcmp(command.c_str(), "/MODE") == 0)
			sendMessage(fd, mode(fd, params));
		else if (strcmp(command.c_str(), "/HELP") == 0)
			sendMessage(fd, HELP);
		else if (strcmp(command.c_str(), "/ACTIVE") == 0)
			sendMessage(fd, active(fd, first_param));
		else
			sendMessage(fd, "Unknown command. Send /HELP to see available commands");
	}
	else {
		//send message to all clients in the same channel
		if (getClientByFd(fd)->current_channel.empty())
			sendMessage(fd, "You are not in a channel. Send JOIN <channel> to join a channel");
		else {
			std::string	channel_name = getClientByFd(fd)->current_channel;
			std::string	nickname = getClientByFd(fd)->getNick();
			std::string	message = nickname + ": " + msg;
			for (std::vector<Channel>::iterator it = _channels.begin(); it != _channels.end(); it++) {
				if (strcmp(it->getName().c_str(), channel_name.c_str()) == 0) {
					it->broadcast(message);
					return;
				}
			}
		}
	}
}

void	Server::handleIrssiMessage(int fd, std::string msg) {
	if (msg.find("\r\n") == std::string::npos)
		return;
	msg = msg.substr(msg.find("\r\n") + 2) + "\r\n";
	while (msg.find("\r\n") != std::string::npos) {
		handleMessage(fd, "/" + msg.substr(0, msg.find("\r\n")));
		msg = msg.substr(msg.find("\r\n") + 2);
	}
}

Client*	Server::getClientByNickname(const std::string nickname) {
	for (IT it = _clients.begin(); it != _clients.end(); ++it) {
		if (strcmp((*it)->getNick().c_str(), nickname.c_str()) == 0) {
			return *it;
		}
	}
	return NULL;
}

std::string	Server::sendPrivateMessage(int fd, std::string msg) {
	size_t pos = msg.find(" ");
	if (pos == std::string::npos)
		return "Invalid message format";

	std::string	nick = msg.substr(0, pos);
	std::string	message = msg.substr(pos + 1);

	Client* client = getClientByNickname(nick);
	if (client == NULL)
		return "User '" + nick + "' not found";

	message = "@" + getClientByFd(fd)->getNick() + ": " + message;
	sendMessage(client->getFd(), message);

	return message;
}

std::string	Server::setNickname(int fd, std::string nickname) {
	for (IT it = _clients.begin(); it != _clients.end(); it++) {
		if (strcmp((*it)->getNick().c_str(), nickname.c_str()) == 0)
			return "Nickname already in use";
	}

	return getClientByFd(fd)->setNick(nickname);
}

std::string	Server::joinChannel(int fd, std::string channel, std::string password) {
	if (strcmp(channel.c_str(), "/JOIN") == 0 || channel[0] == 0)
		return "Invalid channel name";
	if (channel[0] != '#')
		channel = "#" + channel;
	Channel* ch = getChannelByName(channel);
	if (ch == NULL) {
		Channel new_channel(channel, getClientByFd(fd));
		_channels.push_back(new_channel);
		return "Channel " + channel + " created";
	}
	else {
		if (ch->isClient(getClientByFd(fd)))
			return "You are already in channel " + channel;
		if (ch->getPassword().empty())
			return ch->addClient(getClientByFd(fd));
		else
			return ch->addClient(getClientByFd(fd), password);
	}
}

Channel*	Server::getChannelByName(std::string channel) {
	for (std::vector<Channel>::iterator it = _channels.begin(); it != _channels.end(); it++) {
		if (strcmp(it->getName().c_str(), channel.c_str()) == 0) {
			return &(*it);
		}
	}
	return NULL;
}

std::string	Server::listChannels() {
	std::string channels = "Channels:\n";
	for (std::vector<Channel>::iterator it = _channels.begin(); it != _channels.end(); it++) {
		channels += it->getName() + ". topic: " + it->getTopic() + "\n";
	}
	if (channels.back() == '\n')
		channels.pop_back();
	return channels;
}

std::string	Server::leaveChannel(int fd, std::string channel) {
	if (channel[0] != '#')
		channel = "#" + channel;
	Channel* ch = getChannelByName(channel);
	if (ch == NULL)
		return "Channel not found";
	else {
        if (!ch->isClient(getClientByFd(fd)))
            return "You are not in the channel " + channel;
		ch->removeClient(getClientByFd(fd));
		return "Left channel " + channel;
	}
}

std::string	Server::kick(int fd, std::string channel, std::string nickname) {
	Channel* ch = getChannelByName(channel);
	if (ch == NULL)
		return "Channel not found";
	else {
		Client* client = getClientByNickname(nickname);
		if (client == NULL)
			return "User not found";
		else {
			if (ch->isOper(getClientByFd(fd))) {
                if (!ch->isClient(client))
                    return ("Client is not in Channel.");
				ch->removeClient(client);
				return "User " + nickname + " kicked from channel " + channel;
			}
			else
				return "You are not an operator";
		}
	}
}

std::string	Server::topic(int fd, std::string args) {
	if (strcmp(args.c_str(), "/TOPIC") == 0)
		return "Usage: /topic <channel> (<topic>)";
	if (args[0] != '#')
		args = "#" + args;
	size_t pos = args.find_first_of(" \r\n\0");
	std::string	topic = args.substr(pos + 1);
	if (pos == std::string::npos || pos == args.length() - 2) {
		args = args.substr(0, args.find_first_of(" \r\n\0"));
		Channel* ch = getChannelByName(args);
		if (ch == NULL)
			return "Channel not found";
		else
			return "Topic: " + ch->getTopic();
	}

	std::string	channel = args.substr(0, pos);

	Channel* ch = getChannelByName(channel);
	if (ch == NULL)
		return "Channel not found";
	else {
		if (ch->isOper(getClientByFd(fd)) || ch->getTopicRestricted() == false) {
			ch->setTopic(topic);
			return "Topic set to " + topic;
		}
		else
			return "You are not an operator";
	}
}

std::string	Server::invite(int fd, std::string args) {
	std::string channel = args.substr(0, args.find_first_of(" \r\n\0"));
	std::string nickname = args.substr(args.find_first_of(" \r\n\0") + 1);
	if (strcmp(channel.c_str(), "/INVITE") == 0)
		return "Usage: /INVITE <channel> <nickname>";
	if (getChannelByName(channel) == NULL)
		return "Channel not found";
	if (getClientByNickname(nickname) == NULL)
		return "User not found";
	return (getChannelByName(channel)->invite(getClientByFd(fd), getClientByNickname(nickname)));
}

std::string Server::mode(int fd, std::string args) {
	if (strcmp(args.c_str(), "/MODE") == 0)
		return "Usage: /MODE <channel> (<mode>)";
	size_t pos = args.find_first_of(" \r\n\0");
	std::string	channel = args.substr(0, pos);
	std::string	mode = args.substr(pos + 1);
	Channel* ch = getChannelByName(channel);
	if (ch == NULL)
		return "Channel not found";
	if (strcmp(mode.c_str(), channel.c_str()) == 0)
		return (getChannelByName(channel)->getMode());
	return (getChannelByName(channel)->setMode(mode, getClientByFd(fd)));
}

std::string	Server::listUsers() {
	std::string users = "Users:\n";
	for (IT it = _clients.begin(); it != _clients.end(); it++) {
		users += (*it)->getNick() + "\n";
	}
	if (users.back() == '\n')
		users.pop_back();
	return users;
}

std::string Server::active(int fd, std::string channel) {
	if (strcmp(channel.c_str(), "/ACTIVE") == 0)
		return "Usage: /ACTIVE <channel>";
	if (channel[0] != '#')
		channel = "#" + channel;
	Channel* ch = getChannelByName(channel);
	if (ch == NULL)
		return "Channel not found";
	else
		getClientByFd(fd)->current_channel = ch->getName();
	return "Active channel set to " + channel;
}
