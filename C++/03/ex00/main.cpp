#include "ClapTrap.hpp"

int main(){

    ClapTrap    *ran = new ClapTrap;
    ClapTrap    roro("Roro");

    ran->beRepaired(2);
    ran->attack("Roro");
    ClapTrap    temp = *ran;
    temp.takeDamage(10);
    roro.attack("temp");
    std::cout << "Deleting ran\n";
    delete ran;
    temp.takeDamage(10);

    return 0;
}