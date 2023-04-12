#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->_type = "wrong animal";
	std::cout << "Defauld WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << this->getType() << " WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &rhs) {
	if (this == &rhs)
		return (*this);
	_type = rhs.getType();
	return (*this);
}

std::string	WrongAnimal::getType() const {
	return this->_type;
}

void	WrongAnimal::makeSound() const {
	std::cout << "High five" << std::endl;
}