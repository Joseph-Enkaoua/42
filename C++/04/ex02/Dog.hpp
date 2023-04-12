#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
private:
	Brain	*_brain;
public:
	Dog();
	Dog(const Dog &other);
	~Dog();

	Dog & operator=(const Dog &rhs);

	virtual void	makeSound() const;
	void			setIdea(std::string idea, int idea_num);
	std::string		getIdea(int idea_num);
	void			deleteIdea(int idea_num);
};

#endif