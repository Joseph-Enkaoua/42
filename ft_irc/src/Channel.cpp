#include "../headers/Channel.hpp"

Channel::Channel(const std::string &name, Client *client) {
	_name = name;
	_user_limit = INT_MAX;
	_invite_only = false;
	_topic_restricted = false;
	_password = "";
	_topic = "";
	_clients.push_back(client);
	_opers.push_back(client);
	client->current_channel = this->getName();
	client->channels.push_back(this);
}

Channel::~Channel() {}

Channel::Channel(const Channel &rhs) { *this = rhs; }

Channel &Channel::operator=(const Channel &rhs) {
	if (this != &rhs) {
		_name = rhs._name;
		_clients = rhs._clients;
		_opers = rhs._opers;
		_user_limit = rhs._user_limit;
		_invite_only = rhs._invite_only;
		_topic_restricted = rhs._topic_restricted;
		_password = rhs._password;
		_topic = rhs._topic;
	}
	return *this;
}

std::string	Channel::addClient(Client *client) {
	if (_clients.size() >= _user_limit)
		return "Channel is full.";
	if (_invite_only)
		if (!isInvited(client))
			return "Client is not invited.";
	if (_password.empty() == false)
		return "Channel is password protected.";

	_clients.push_back(client);
	client->current_channel = this->getName();
	client->channels.push_back(this);

	std::string message = client->getNick() + " JOINED";
	broadcast(message, client);
	return "Joined to channel " + getName();
}

std::string	Channel::addClient(Client *client, std::string password) {
	if (_clients.size() == _user_limit)
		return "Channel is full.";
	if (_invite_only)
		if (!isInvited(client))
			return "Client is not invited.";
	if (strcmp(_password.c_str(), password.c_str()) != 0)
		return "Incorrect password.";

	_clients.push_back(client);
	client->current_channel = this->getName();
	client->channels.push_back(this);

	std::string message = client->getNick() + " JOINED";
	broadcast(message, client);
	return "Joined to channel " + getName();
}

std::string Channel::getName() const { return _name; }

std::string Channel::getPassword() const { return _password; }

std::string Channel::setPassword(std::string pass) { _password = pass; return "Password set."; }

void	Channel::sendMessage(int fd, std::string message) {
	if (message.back() == '\0')
		message.erase(message.length() - 1);
	message += "\r\n";

	size_t	len = message.length();
	while (len > 0) {
		int	ret = send(fd, message.c_str(), len, 0);
		if (ret == -1) {
			std::cout << "SEND ERROR: " << strerror(errno) << std::endl;
			return;
		}
		message = message.substr(ret);
		len -= ret;
	}
}

void	Channel::broadcast(std::string message) {
	// message = _name + " -> " + message;
	for (clients_iterator it = _clients.begin(); it != _clients.end(); it++) {
		sendMessage((*it)->getFd(), message);
	}
}

void	Channel::broadcast(std::string message, Client *exclude) {
	// message = _name + " -> " + message;
	for (clients_iterator it = _clients.begin(); it != _clients.end(); it++) {
		if (*it != exclude)
			sendMessage((*it)->getFd(), message);
	}
}

std::string	Channel::removeClient(Client *client) {
	std::string message = client->getNick() + " LEFT";
	broadcast(message);
	client->current_channel = "";
	_clients.erase(std::remove(_clients.begin(), _clients.end(), client), _clients.end());
	_opers.erase(std::remove(_opers.begin(), _opers.end(), client), _opers.end());
	client->channels.erase(std::remove(client->channels.begin(), client->channels.end(), this), client->channels.end());
	return "Client removed from channel.";
}

void	Channel::setUserLimit(int limit) { _user_limit = limit; }

void	Channel::setInviteOnly(bool invite_only) { _invite_only = invite_only; }

void	Channel::setTopicRestricted(bool topic_restricted) { _topic_restricted = topic_restricted; }

void	Channel::setTopic(std::string topic) { _topic = topic; }

void	Channel::setOper(Client *client) { _opers.push_back(client); }

std::string	Channel::getTopic() const { return _topic; }

bool	Channel::getTopicRestricted() const { return _topic_restricted; }

bool	Channel::getInviteOnly() const { return _invite_only; }

bool	Channel::isOper(Client *client) {
	for (clients_iterator it = _opers.begin(); it != _opers.end(); it++) {
		if (*it == client)
			return true;
	}
	return false;
}

std::string	Channel::setMode(std::string args, Client *client) {
	if (isOper(client) == false)
		return "You are not an operator.";
	std::string	mode = args.substr(0, args.find_first_of(" "));
	args = args.substr(args.find_first_of(" ") + 1);
	if (strcmp(mode.c_str(), "i") == 0) {
		_invite_only = !_invite_only;
		return "Invite only mode set to " + std::to_string(_invite_only);
	} else if (strcmp(mode.c_str(), "t") == 0) {
		_topic_restricted = !_topic_restricted;
		return "Topic restricted mode set to " + std::to_string(_topic_restricted);
	} else if (strcmp(mode.c_str(), "l") == 0) {
		try {
			_user_limit = std::stoi(args);
			return "User limit set to " + std::to_string(_user_limit);
		} catch (std::exception &e) {
			_user_limit = INT_MAX;
			return "User limit set to max";
		}
	} else if (strcmp(mode.c_str(), "k") == 0) {
		if (strcmp(args.c_str(), mode.c_str()) == 0) {
			_password = "";
			return "Password removed.";
		}
		else {
			_password = args;
			return "Password set to *" + args + "*";
		}
	} else if (strcmp(mode.c_str(), "o") == 0) {
		if (args.empty() == false) {
			for (clients_iterator it = _clients.begin(); it != _clients.end(); it++) {
				if (strcmp(args.c_str(), (*it)->getNick().c_str()) == 0) {
					if (isOper(*it) == true) {
						_opers.erase(std::remove(_opers.begin(), _opers.end(), *it), _opers.end());
						return args + " is no longer an operator.";
					}
					else {
						_opers.push_back(*it);
						return args + " is now an operator.";
					}
				}
			}
			return "Client not found.";
		}
		else {
			return "No client specified.";
		}
	} else{
		return "Invalid mode.";
	}

}

std::string	Channel::getMode() {
	std::string mode = "Channel modes:";
	mode += "invite only: " + std::to_string(_invite_only) + "\ntopic restricted: " + \
	std::to_string(_topic_restricted) + "\nuser limit: " + std::to_string(_user_limit) + \
	"\npassword required: " + std::to_string(_password.empty() == false);
	return mode;
}

bool	Channel::isClient(Client *client) {
	for (clients_iterator it = _clients.begin(); it != _clients.end(); it++) {
		if (*it == client)
			return true;
	}
	return false;
}

std::string	Channel::invite(Client *client, Client *target) {
	if (isOper(client) == false)
		return "You are not an operator.";
	if (_invite_only == false)
		return "Channel is not invite only.";
	if (isClient(target) == true)
		return "Client is already in channel.";
	_invited.push_back(target);
	return "Client invited.";
}

bool	Channel::isInvited(Client *client) {
	for (clients_iterator it = _invited.begin(); it != _invited.end(); it++) {
		if (*it == client)
			return true;
	}
	return false;
}
