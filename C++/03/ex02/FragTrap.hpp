#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string str);
	FragTrap(const FragTrap &other);
	~FragTrap();

	FragTrap & operator=(const FragTrap & rhs);

	void	attack(const std::string &target);
	void	highFivesGuys( void );
};

#endif