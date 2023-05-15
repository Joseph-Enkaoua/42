#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <string>
# include <stack>

class RPN {
private:
	double				_tmp1;
	double				_tmp2;
	std::string			_input;
	std::stack<double>	_stack;
public:
	RPN();
	RPN(std::string input);
	RPN(const RPN &rhs);
	~RPN();
	RPN &	operator = (const RPN &rhs);
	void	activate_cal();
	int		parse_input();
	int		ret_err(std::string str);
	void	calculate(int oper);
};

#endif