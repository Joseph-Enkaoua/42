#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &weapon) : name(str), human_weapon(weapon) {}

HumanA::~HumanA(){
}

void	HumanA::attack(){
	std::cout << name << " attacks with their " << human_weapon.getType() << std::endl; 
}