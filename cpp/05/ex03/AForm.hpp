#ifndef AForm_HPP
# define AForm_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class AForm {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:
	AForm(std::string name, int to_sign, int to_execute);
	virtual ~AForm();

	std::string 	getName() const;
	bool			getIsSigned() const;
	int				getToSign() const;
	int				getToExecute() const;
	void			beSigned(Bureaucrat *bob);
	void			checkBeforeExecute(Bureaucrat const & bob) const;
	virtual void	execute(Bureaucrat const & executor) const = 0;

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

	class UnsignedFormException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Error: form is not signed");
		}
	};
};

std::ostream	&operator<<(std::ostream &out, const AForm &tmp);

#endif