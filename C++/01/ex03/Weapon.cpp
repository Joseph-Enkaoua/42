#include "Weapon.hpp"

Weapon::Weapon(void){
}

Weapon::Weapon(std::string str){
	setType(str);
}

Weapon::~Weapon(void){
}

const std::string&	Weapon::getType() const {
	return (_type);
}

void	Weapon::setType(std::string newName){
	_type = newName;
}