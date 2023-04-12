#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Default Cat constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat &other) {
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = other;
}

Cat::Cat(const Animal &other) : Animal(other) {
	std::cout << "Copy Cat constructor called" << std::endl;
	_type = other.getType();
	_brain = new Brain();
}

Cat::~Cat(){
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat & Cat::operator=(const Cat &rhs){
    if (this == &rhs)
        return (*this);
	_type = rhs._type;
	_brain = new Brain(*rhs._brain);
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Meowww" << std::endl;
}

void	Cat::setIdea(std::string idea, int idea_num) {
	if (idea_num < 0 || idea_num > 99){
		std::cout << "Invalid idea number" << std::endl;
		return ;
	}
	_brain->_ideas[idea_num] = idea;
}

std::string	Cat::getIdea(int idea_num) {
	if (idea_num < 0 || idea_num >= 100){
		std::cout << "Invalid idea number" << std::endl;
		return NULL;
	}
	return _brain->_ideas[idea_num];
}

void	Cat::deleteIdea(int idea_num){
	if (idea_num < 0 || idea_num >= 100){
		std::cout << "Invalid idea number" << std::endl;
		return ;
	}
	_brain->_ideas[idea_num] = "";
}
