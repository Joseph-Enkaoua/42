#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other.getType()) {
	std::cout << "Copy Cat constructor called" << std::endl;
}

Cat::Cat(const Animal &other) : Animal(other) {
	std::cout << "Copy Cat constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

Cat & Cat::operator=(const Cat &rhs){
    if (this == &rhs)
        return (*this);
	_type = rhs.getType();
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Meowww" << std::endl;
}
