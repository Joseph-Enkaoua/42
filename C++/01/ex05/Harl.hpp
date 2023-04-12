#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <string>

class Harl {
private:
	void		debug( void );
	void		info( void );
	void		warning( void );
	void		error( void );
    std::string	_level[4];
	void		(Harl::*_f[4])( void );
public:
	Harl();
	~Harl();
	void	complain( std::string level );
};

#endif