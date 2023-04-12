#include "Zombie.hpp"

Zombie::Zombie(void){
}

Zombie::~Zombie(void){
}

void    Zombie::set_name(std::string name){
    _name = name;
}

void    Zombie::announce(void){
    std::cout << "My name is : " << _name << std::endl;
}