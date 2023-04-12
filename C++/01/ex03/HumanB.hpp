#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB {
public:
	HumanB();
	HumanB(std::string str);
	~HumanB();
	std::string name;
	Weapon      *human_weapon;
	void        attack();
	void        setWeapon(Weapon *weapon);
};

#endif