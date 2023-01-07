#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45) {
	_target = "undefined";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45) {
	_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	try
	{
		checkBeforeExecute(executor);
		std::cout << "Bzzzzzzzz wsh wsh wsh wsh drrrrr" << std::endl;
		std::srand(time(NULL));
		int ran  = std::rand();
		if (ran % 2) {
			std::cout << _target << " has been robotomized successfully" << std::endl;
		}
		else {
			std::cout << "Oups! our robotomy failed :F" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}
