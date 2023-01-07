#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << "Default Scav constructor called" << std::endl;
    _name = "random";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string str){
	std::cout << "Default Scav constructor (str) called" << std::endl;
	_name = str;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other){
	std::cout << "Copy Scav constructor called" << std::endl;
	*this = other;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & rhs){
	std::cout << "Scav: Copy assignment operator called" << std::endl;
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "Scav: Destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target){
	if (_energy_points > 0 && _hit_points > 0){
		_energy_points--;
		std::cout << "ScavTrap " << _name << " attacks " << target << 
		", cousing " << _attack_damage << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate( void ){
	std::cout << "ScavTrap " << _name << " is now in gate keeper mode" << std::endl;
}
