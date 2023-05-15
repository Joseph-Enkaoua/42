#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string input) {
	_input = input;
	activate_cal();
}

RPN::RPN(const RPN &rhs) {
	*this = rhs;
}

RPN::~RPN() {}

RPN & RPN::operator = (const RPN &rhs) {
	_input = rhs._input;
	this->activate_cal();
	return (*this);
}

int	RPN::ret_err(std::string str) {
	std::cout << str << "\n";
	return 0;
}

int	RPN::parse_input() {
	char	c;
	int		i = -1;

	while (_input[++i]) {
		c = _input[i];
		if ((c != ' ' && c != '+' && c != '-' && c != '*' && c != '/' \
			&& !isdigit(c)) || !isdigit(_input[0]) \
			|| (c != ' ' && (_input[i + 1] != ' ' && _input[i + 1] != '\0')))
			return ret_err("Error: bad input");
		if (_input[i + 1] == '\0' && isdigit(c))
			return ret_err("Error: bad input");
	}
	return 1;
}

void	RPN::calculate(int oper) {
	_tmp1 = _stack.top();
	_stack.pop();
	_tmp2 = _stack.top();
	_stack.pop();
	if (oper == '*')
		_stack.push(_tmp2 * _tmp1);
	if (oper == '/')
		_stack.push(_tmp2 / _tmp1);
	if (oper == '+')
		_stack.push(_tmp2 + _tmp1);
	if (oper == '-')
		_stack.push(_tmp2 - _tmp1);
}

void	RPN::activate_cal() {
	int	i = -1;
	
	if (!parse_input())
		return ;
	while (_input[++i]) {
		if (isdigit(_input[i]))
			_stack.push(_input[i] - 48);
		else if (!isspace(_input[i]))
			calculate(_input[i]);
	}

	std::cout << _stack.top() << "\n";
}
