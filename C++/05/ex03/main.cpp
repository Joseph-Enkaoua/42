#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(){
	try {
		Bureaucrat	moses("moses", 3);
		Bureaucrat	david("david", 45);
		PresidentialPardonForm	presidential("tree");
		RobotomyRequestForm		robotomy("garden");
		ShrubberyCreationForm	shrub("sattelite");
		std::cout << moses.getGrade() << std::endl;
		moses.decreaseGrade();
		std::cout << moses << std::endl;
		moses.increaseGrade();
		std::cout << moses << std::endl;
		moses.increaseGrade();
		robotomy.beSigned(&moses);
		david.signForm(robotomy);
		shrub.beSigned(&moses);
		shrub.execute(moses);
		moses.signForm(presidential);
		presidential.execute(moses);
		robotomy.execute(david);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 0;
	}
	Intern	intern;
	AForm	*form;
	form = intern.makeForm("presidential pardon", "Christoph");
	Bureaucrat	moses("moses", 3);
	form->beSigned(&moses);
	form->execute(moses);
	return 0;
}
