#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other.getType()) {
	std::cout << "Cpoy WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat &rhs){
    if (this == &rhs)
        return (*this);
	this->_type = rhs._type;
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << "Meowww" << std::endl;
}
