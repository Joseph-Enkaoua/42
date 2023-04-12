#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Default Dog constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other) {
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = other;
}

Dog::Dog(const Animal &other) : Animal(other) {
	std::cout << "Copy Dog constructor called" << std::endl;
	_type = other.getType();
	_brain = new Brain();
}

Dog::~Dog(){
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog & Dog::operator=(const Dog &rhs){
    if (this == &rhs)
        return (*this);
	_type = rhs._type;
	_brain = new Brain(*rhs._brain);
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "Uoaff" << std::endl;
}

void	Dog::setIdea(std::string idea, int idea_num) {
	if (idea_num < 0 || idea_num >= 100){
		std::cout << "Invalid idea number" << std::endl;
		return ;
	}
	_brain->_ideas[idea_num] = idea;
}

std::string	Dog::getIdea(int idea_num) {
	if (idea_num < 0 || idea_num >= 100){
		std::cout << "Invalid idea number" << std::endl;
		return NULL;
	}
	return _brain->_ideas[idea_num];
}

void	Dog::deleteIdea(int idea_num){
	if (idea_num < 0 || idea_num >= 100){
		std::cout << "Invalid idea number" << std::endl;
		return ;
	}
	_brain->_ideas[idea_num] = "";
}
