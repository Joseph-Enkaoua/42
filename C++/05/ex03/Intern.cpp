#include "Intern.hpp"

Intern::Intern() {
	_f[0] = &Intern::creatPresidential;
	_f[1] = &Intern::creatRobotomy;
	_f[2] = &Intern::creatShubbery;
	_form[0] = "presidential pardon";
	_form[1] = "robotomy request";
	_form[2] = "shrubbery creation";
}

Intern::~Intern() {}

static std::string	setFormName(std::string name){
	int s = name.length();
	for (int i = 0;i < s;i++) {
		name[i] = tolower(name[i]);
	}
	return name;
}

AForm	*Intern::makeForm(std::string form, std::string target) {
	form = setFormName(form);
	for (int i = 0;i < 3;i++) {
		if (form == _form[i]) {
			std::cout << "Intern creates " << form << std::endl;
		 	return (this->*_f[i])(target);
		}
	}
	std::cout << "Error: form didn't found" << std::endl;
	return NULL;
}

AForm	*Intern::creatPresidential(std::string str) {
	return (new PresidentialPardonForm(str));
}

AForm	*Intern::creatRobotomy(std::string str) {
	return (new RobotomyRequestForm(str));
}

AForm	*Intern::creatShubbery(std::string str) {
	return (new ShrubberyCreationForm(str));
}
