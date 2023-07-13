#ifndef SERVER_HPP
# define SERVER_HPP
# include <iostream>
# include <sys/socket.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <vector>
# include <arpa/inet.h>
# include <errno.h>
# include <poll.h>
# include "Client.hpp"
# include "Channel.hpp"
# include "Globals.h"

# define MAX_CLIENTS 24
# define BUFFER_SIZE 1024
# define IT std::vector<Client*>::iterator

# define HELP "Available commands:\n/USERS   = list all connected users\n/NICK    = set a new nickname\n\
/USER    = set a new username\n/MYNICK  = what's my nickname?\n/MYUSER  = what's my username?\n\
/PRIVMSG = send a private message\n/JOIN    = create or join a channel\n/PART    = leave a channel\n\
/LIST    = list available channels\n/QUIT    = leave IRC server\n/HELP    = list available commands\n\
/KICK    = kick user from channel as its operator\n/INVITE  = invite a user to a close channel\n\
/TOPIC   = show or edit channel topic\n/MODE    = view or edit channel mode\n/ACTIVE   = set active channel"

class Server {
private:																
	std::string				_ip;
	std::string				_pass;
	int						_port;
	int						_fd;
	int						_num_fds;
	int						_num_users;
	struct pollfd			_fds[MAX_CLIENTS + 1];
	std::vector<Client*>	_clients;
	std::vector<Channel>	_channels;

	Server(const Server &rhs);
	Server &operator=(const Server &rhs);
public:
	Server(const std::string &ip, int port, std::string pass);
	~Server();

	std::string	getIp() const;
	std::string	getPass() const;
	int	getPort() const;
	int	exitError(const std::string &str);
	int	exitSuccess();

	void		run();
	void		waitForSignal();
	int			acceptConnection();
	int			readMessage(int fd);
	void		authClient(int fd, const std::string &pass);
	void		disconnectClient(int fd);
	void		sendMessage(int fd, std::string msg);
	Client*		getClientByFd(int fd);
	Client* 	getClientByNickname(const std::string nickname);
	void		handleMessage(int fd, std::string msg);
	void		handleIrssiMessage(int fd, std::string msg);
	std::string	sendPrivateMessage(int fd, std::string msg);
	std::string	setNickname(int fd, std::string msg);
	std::string joinChannel(int fd, std::string channel, std::string password);
	Channel*	getChannelByName(const std::string name);
	std::string	listChannels();
	std::string	leaveChannel(int fd, std::string channel);
	std::string	kick(int fd, std::string channel, std::string nickname);
	std::string	topic(int fd, std::string args);
	std::string	invite(int fd, std::string args);
	std::string	mode(int fd, std::string args);
	std::string	listUsers();
	std::string active(int fd, std::string channel);
};

#endif