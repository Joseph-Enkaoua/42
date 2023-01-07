#include "Zombie.hpp"

Zombie::Zombie(){
    _name = "foo";
}

Zombie::Zombie(std::string name){
    _name = name;
};

Zombie::~Zombie(void){
    std::cout << "Destroy " << _name << std::endl;
};

void    Zombie::announce(void){
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};
