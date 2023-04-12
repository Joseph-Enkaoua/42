#include "Zombie.hpp"

int main(void){
    Zombie  *vivi;

    vivi = zombieHorde(3, "Eminem");
    for(int i = 0; i < 3; i++){
        vivi[i].announce();
    }
    delete [] vivi;
    return (0);
}