#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Default Dog constructor called" << std::endl;
	this->_type = "Dog"; 
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other) {
	std::cout << "Cpoy Dog constructor called" << std::endl;
	*this = other;
}

Dog::~Dog(){
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog & Dog::operator=(const Dog &rhs){
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	this->_brain = new Brain(*rhs._brain);
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
