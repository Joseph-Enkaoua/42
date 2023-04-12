#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
private:
	Brain	*_brain;
public:
	Dog();
	Dog(const Dog &other);
	Dog(const Animal &other);
	~Dog();

	Dog & operator=(const Dog &rhs);

	void			makeSound() const;
	void			setIdea(std::string idea, int idea_num);
	std::string		getIdea(int idea_num);
	void			deleteIdea(int idea_num);
};

#endif