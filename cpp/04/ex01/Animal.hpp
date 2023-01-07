#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
	std::string	_type;
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &other);
	virtual ~Animal();

	Animal & operator=(const Animal &rhs);
	
	std::string		getType() const;
	virtual void	makeSound() const;
};

#endif