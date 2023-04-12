#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
public:
	WrongDog();
	WrongDog(const WrongDog &other);
	~WrongDog();
	WrongDog & operator=(const WrongDog &rhs);
	void	makeSound() const;
};

#endif