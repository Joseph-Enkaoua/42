#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <stdexcept>
# include <iostream>
# include <string>
# include <iomanip>

class Converter {
private:
	std::string	_input;
	char		_char;
	int			_int;
	float		_float;
	double		_double;

	void	findType(std::string str);
	void	charType(char c);
	bool	isInt(std::string str);
	bool	isFloat(std:: string str);
	bool	isDouble(std::string str);
	void	printValue();
	void	lastOne(std::string str);
public:
	Converter();
	Converter(std::string str);
	~Converter();
	Converter(const Converter &other);

	Converter & operator=(const Converter & rhs);

	class invalidValueException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return("Error: invalid input");
		}
	};
};

#endif