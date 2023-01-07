#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include <time.h>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm();

	void	execute(Bureaucrat const & executor) const;
};


#endif
