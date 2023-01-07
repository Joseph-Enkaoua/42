#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string.h>

class Brain {
public:
	Brain();
	Brain(const Brain &other);
	~Brain();

	Brain & operator=(const Brain & rhs);

	std::string _ideas[100];
};

#endif