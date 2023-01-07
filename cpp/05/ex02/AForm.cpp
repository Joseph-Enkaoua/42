#include "AForm.hpp"

AForm::AForm(std::string name, int to_sign, int to_execute) : _name(name),
_isSigned(false), _gradeToSign(to_sign), _gradeToExecute(to_execute) {
	if (_gradeToExecute < 1 || _gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << name << " was created successfully" << std::endl;
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return _name;
}

bool	AForm::getIsSigned()const {
	return _isSigned;
}

int	AForm::getToSign() const {
	return _gradeToSign;
}

int	AForm::getToExecute() const {
	return _gradeToExecute;
}

void	AForm::beSigned(Bureaucrat *bob) {	
	try
	{
		if (bob->getGrade() <= this->getToSign()){
			_isSigned = true;
			std::cout << bob->getName() << " signed " << this->getName() << std::endl;
		}
		else
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	AForm::checkBeforeExecute(Bureaucrat const & bob) const {
	if (!this->getIsSigned())
		throw AForm::UnsignedFoemException();
	else if (bob.getGrade() > this->getToExecute())
		throw AForm::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out, const AForm &tmp) {
	if (tmp.getIsSigned()) {
		out << "AForm " << tmp.getName() << " is signed and requires rank " <<
		tmp.getToSign() << " to sign and " << tmp.getToExecute() << " to execute.";
	}
	else {
		out << "AForm " << tmp.getName() << " is NOT signed and requires rank " <<
		tmp.getToSign() << " to sign and " << tmp.getToExecute() << " to execute.";
	}
	return out;
}
