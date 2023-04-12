#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <cstdlib>

class Span {
private:
	std::vector<int>    vec;
	unsigned int  maxSize;
public:
	Span();
	Span(unsigned int size);
	Span(const Span &rhs);
	~Span();

	Span& operator=(const Span& rhs);

	void	addNumber(int num);
	void	addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
	int		shortestSpan();
	int		longestSpan();

	class NoSpaceLeftException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Error: container is full");
		}
	};

	class CantFindSpanException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Error: not enough values to find span");
		}
	};
};

#endif