#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){

    std::cout << "\033[1;32m==========       CONSTRUCTOR      ==========\e[0m" << std::endl << std::endl;

	ScavTrap    scav("Super Vietdu91");
	FragTrap	frag("Super Thaidu93");

	std::cout << std::endl;

	std::cout << "\033[1;34m==========       ACTION !!!       ==========\e[0m" << std::endl << std::endl;

	scav.attack("Richard Nixon");
	scav.takeDamage(99);
	scav.beRepaired(150);
	std::cout << std::endl;
	scav.guardGate();
	std::cout << std::endl;
	scav.takeDamage(789);
	scav.beRepaired(150);
	std::cout << std::endl;

	std::cout << "\033[1;34m= = = = = = = = = = = = = = = = = = = = = =\e[0m" << std::endl << std::endl;

	frag.attack("Donald Trump");
	frag.takeDamage(99);
	frag.beRepaired(150);
	std::cout << std::endl;
	frag.highFivesGuys();
	std::cout << std::endl;
	frag.takeDamage(789);
	frag.beRepaired(150);
	std::cout << std::endl;

	std::cout << "\033[1;31m==========       DESTRUCTOR       ==========\e[0m" << std::endl << std::endl;

    return 0;
}