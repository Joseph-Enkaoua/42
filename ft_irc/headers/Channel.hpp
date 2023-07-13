#ifndef CHANNEL_HPP
# define CHANNEL_HPP
# include <iostream>
# include <vector>

class Client;
typedef std::vector<Client *>::iterator clients_iterator;

class Channel {
private:
	std::string				_name;
	std::vector<Client*>	_clients;
	std::vector<Client*>	_opers;
	size_t					_user_limit;
	bool					_invite_only;
	bool					_topic_restricted;
	std::string				_password;
	std::string				_topic;
	std::vector<Client*>	_invited;
public:
	Channel(const std::string &name, Client *client);
	Channel(const Channel &rhs);
	Channel &operator=(const Channel &rhs);
	~Channel();

	std::string	addClient(Client *client);
	std::string	addClient(Client *client, std::string password);
	std::string	getName() const;
	std::string getPassword() const;
	std::string	setPassword(std::string pass);
	void		sendMessage(int fd, std::string message);
	void		broadcast(std::string message);
	void		broadcast(std::string message, Client *exclude);
	std::string	removeClient(Client *client);
	void		setTopic(std::string topic);
	std::string	getTopic() const;
	void		setUserLimit(int limit);
	void		setInviteOnly(bool invite_only);
	bool		getInviteOnly() const;
	void		setTopicRestricted(bool topic_restricted);
	bool		getTopicRestricted() const;
	void		setOper(Client *client);
	bool		isOper(Client *client);
	std::string	setMode(std::string mode, Client *client);
	std::string	getMode();
	bool		isClient(Client *client);
	std::string	invite(Client *client, Client *target);
	bool		isInvited(Client *client);
};

# include "Client.hpp"

#endif