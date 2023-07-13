#include "../headers/Client.hpp"

Client::Client(int fd, struct sockaddr_in address, socklen_t address_len) {
	_user = "";
	_nick = "";
    buffer = "";
	_fd = fd;
	_address = address;
	_address_len = address_len;
	is_auth = false;
	current_channel = "";
}

Client::~Client() {}

Client & Client::operator=(const Client &rhs) { (void) rhs; return *this; }

int	Client::getFd() const { return _fd; }

struct sockaddr_in Client::getAddress() const { return _address; }

socklen_t Client::getAddressLen() const { return _address_len; }

std::string Client::getIp() const { return inet_ntoa(_address.sin_addr); }

std::string	Client::getPort() const {
	std::stringstream ss;
	ss << ntohs(_address.sin_port);
	return ss.str();
}

std::string	Client::setUser(std::string user) { _user = user; return NAMESETMSG; }

std::string	Client::getUser() const { return _user; }

std::string	Client::setNick(std::string nick) { _nick = nick; return NICKSETMSG; }

std::string	Client::getNick() const { return _nick; }
