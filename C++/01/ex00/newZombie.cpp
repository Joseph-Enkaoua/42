#include "Zombie.hpp"

Zombie* newZombie(std::string name){
    Zombie  *retzombie;
    retzombie = new Zombie(name);
    return (retzombie);
}