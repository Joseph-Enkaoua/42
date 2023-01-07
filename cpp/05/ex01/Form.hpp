#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:
	Form();
	Form(std::string name, int to_sign, int to_execute);
	~Form();

	std::string getName() const;
	bool		getIsSigned() const;
	int			getToSign() const;
	int			getToExecute() const;
	void		beSigned(Bureaucrat *bob);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Error: grade too high");
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Error: grade too low");
		}
	};
};

std::ostream	&operator<<(std::ostream &out, const Form &tmp);

#endif