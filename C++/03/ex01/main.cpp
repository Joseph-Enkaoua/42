#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){

    ScavTrap    vivi("Vivi");
    ScavTrap    roro("Roro");

    vivi.beRepaired(2);
    vivi.attack("Roro");
    roro.takeDamage(10);
    vivi.guardGate();

    return 0;
}