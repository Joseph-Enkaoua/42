#include "Zombie.hpp"

int main(void){
    Zombie  zoo("zoo");

    Zombie *yossi = newZombie("yossi");
    yossi->announce();
    randomChump("dani");
    delete yossi;
    return (0);
}