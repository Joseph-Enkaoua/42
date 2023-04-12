#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string.h>
# include <iostream>

class WrongAnimal {
protected:
    std::string	_type;
public:
	virtual ~WrongAnimal() = 0;
		
	virtual void	makeSound() const = 0;
};

#endif