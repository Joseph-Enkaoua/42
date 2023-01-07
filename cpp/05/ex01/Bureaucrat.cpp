#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Borat") {
	_grade = 150;
	std::cout << "Default Bureaucrat Borat was created successfully" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat " << name << " was created successfully" << std::endl;
}

int	Bureaucrat::setGrade(int grade){
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		_grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 0;
	}
	return 1;
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::increaseGrade(){
	if (setGrade(_grade - 1))
		std::cout << "increased " << getName() << " grade" << std::endl; 
}

void	Bureaucrat::decreaseGrade(){
	if (setGrade(_grade + 1))
		std::cout << "decreased " << getName() << " grade" << std::endl; 
}

void	Bureaucrat::signForm(Form form) {
	if (_grade <= form.getToSign()){
		form.beSigned(this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	else
		std::cout << _name << " couldn't sign " << form.getName() <<
		" because he doesn't have the required grade to sign this form" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &tmp){
	out << tmp.getName() << " bureaucrat grade " << tmp.getGrade() << ".";
	return out;
}
