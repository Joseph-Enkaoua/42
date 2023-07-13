#ifndef CLIENT_HPP
# define CLIENT_HPP
# include <iostream>
# include <netinet/in.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <sstream>
# include <vector>

# define NAMESETMSG "Username successfully set."
# define NICKSETMSG "Nickname successfully set."

class Channel;

class Client {
private:
	std::string			_user;
	std::string			_nick;
	int					_fd;
	struct sockaddr_in	_address;
	socklen_t			_address_len;
	Client(const Client &rhs);
	Client & operator=(const Client &rhs);
public:
	std::vector<Channel*>	channels;
	std::string			current_channel;
    std::string			buffer;
	bool				is_auth;
	Client(int fd, struct sockaddr_in address, socklen_t address_len);
	~Client();

	int					getFd() const;
	struct sockaddr_in	getAddress() const;
	socklen_t			getAddressLen() const;
	std::string			getIp() const;
	std::string			getPort() const;
	std::string			setUser(std::string user);
	std::string			getUser() const;
	std::string			setNick(std::string nick);
	std::string			getNick() const;
};

# include "Channel.hpp"

#endif