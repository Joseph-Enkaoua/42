#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	*this = other;
	std::cout << "Copy Brain constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain & Brain::operator=(const Brain & rhs){
	if (this == &rhs)
		return (*this);
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}
