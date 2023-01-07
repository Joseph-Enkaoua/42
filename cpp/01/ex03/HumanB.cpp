#include "HumanB.hpp"

HumanB::HumanB(){}

HumanB::HumanB(std::string str) : name(str), human_weapon(NULL) {}

HumanB::~HumanB(){}

void    HumanB::setWeapon(Weapon *weapon){
	human_weapon = weapon;
}

void    HumanB::attack(){
	if (human_weapon)
		std::cout << name << " attacks with their " << human_weapon->getType() << std::endl; 
}