#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string.h>
# include <iostream>

class WrongAnimal {
protected:
    std::string	_type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &other);
	~WrongAnimal();
	
	WrongAnimal & operator=(const WrongAnimal &rhs);
	
	std::string	getType() const;
	void		makeSound() const;
};

#endif