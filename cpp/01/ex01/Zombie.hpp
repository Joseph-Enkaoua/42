#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
private:
    std::string _name;
public:
    Zombie(void);
    ~Zombie(void);
    void    set_name(std::string name);
    void    announce();
};

Zombie*    zombieHorde(int num, std::string name);

#endif