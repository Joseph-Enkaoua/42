#include "Form.hpp"

Form::Form() : _name("randomForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Default Form randomForm was created successfully" << std::endl;
}

Form::Form(std::string name, int to_sign, int to_execute) : _name(name),
_isSigned(false), _gradeToSign(to_sign), _gradeToExecute(to_execute) {
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form " << name << " was created successfully" << std::endl;
}

Form::~Form() {}

std::string Form::getName() const {
	return _name;
}

bool	Form::getIsSigned()const {
	return _isSigned;
}

int	Form::getToSign() const {
	return _gradeToSign;
}

int	Form::getToExecute() const {
	return _gradeToExecute;
}

void	Form::beSigned(Bureaucrat *bob) {	
	try
	{
		if (bob->getGrade() <= this->getToSign())
			_isSigned = true;
		else
			throw Form::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

std::ostream	&operator<<(std::ostream &out, const Form &tmp) {
	if (tmp.getIsSigned()) {
		out << "Form " << tmp.getName() << " is signed and requires rank " <<
		tmp.getToSign() << " to sign and " << tmp.getToExecute() << " to execute.";
	}
	else {
		out << "Form " << tmp.getName() << " is NOT signed and requires rank " <<
		tmp.getToSign() << " to sign and " << tmp.getToExecute() << " to execute.";
	}
	return out;
}
