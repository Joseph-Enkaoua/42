#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	Span er = Span(100000);

	std::cout << "-------------------42 test-------------------" << std::endl;

	//adding numbers and finding shortest/longest span:
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;		

	std::cout << "-------------------Exceptoin test when full-------------------" << std::endl;

	try {
		//span is full
		sp.addNumber(46);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		//span is empty
		std::cout << er.shortestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "-------------------10000 numbers + iterators addNumber-------------------" << std::endl;

	std::vector<int>	tmp(10000);
	std::vector<int>::iterator	b;
	std::vector<int>::iterator	e;

	try {
		for (size_t i = 0; i < 10000; i++)
			tmp.push_back(rand());
		b = tmp.begin();
		e = tmp.end();
		er.addNumber(b, e);
		std::cout << er.shortestSpan() << std::endl;
		std::cout << er.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
