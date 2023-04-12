#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
protected:
    std::string	_name;
	int		_hit_points;
	int		_energy_points;
	int		_attack_damage;

public:
	ClapTrap();
	ClapTrap(std::string str);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();

	ClapTrap & operator=(const ClapTrap & rhs);
	
	virtual void	attack(const std::string &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

};

#endif