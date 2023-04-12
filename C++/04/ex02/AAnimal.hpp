#ifndef AAnimal_HPP
# define AAnimal_HPP

#include <iostream>
#include <string>

class AAnimal {
protected:
	std::string	_type;
public:
	virtual ~AAnimal() = 0;
	
	virtual void	makeSound() const = 0;
};

#endif