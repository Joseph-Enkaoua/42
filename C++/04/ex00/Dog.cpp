#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other.getType()) {
	std::cout << "Cpoy Dog constructor called" << std::endl;
}

Dog::Dog(const Animal &other) : Animal(other) {
	std::cout << "Cpoy Dog constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog & Dog::operator=(const Dog &rhs){
	if (this == &rhs)
		return (*this);
	_type = rhs.getType();
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Uoaff" << std::endl;
}
