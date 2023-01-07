#include "Span.hpp"

Span::Span() : maxSize(0) {}

Span::Span(unsigned int size) : maxSize(size) {}

Span::Span(const Span &rhs) : maxSize(rhs.maxSize) {
	vec = rhs.vec;
}

Span::~Span() {}

Span& Span::operator=(const Span &rhs) {
	if (this == &rhs)
		return *this;
	maxSize = rhs.maxSize;
	vec = rhs.vec;
	return *this;
}

void    Span::addNumber(int num) {
	if (vec.size() == maxSize)
		throw NoSpaceLeftException();
	vec.push_back(num);
}

void	Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	while (start <= end) {
		addNumber(*start);
		start++;
	}
}

int		Span::shortestSpan() {
	int distance = INT_MAX;
	if (vec.size() < 2)
		throw CantFindSpanException();
	for (size_t i = 0; i < vec.size(); i++) {
		for (size_t k = 0; k < vec.size(); k++) {
			if (vec.at(i) - vec.at(k) < distance && vec.at(i) - vec.at(k) > 0)
				distance = vec.at(i) - vec.at(k);
		}
	}
	return distance;
}

int		Span::longestSpan() {
	int distance = 0;
	if (vec.size() < 2)
		throw CantFindSpanException();
	for (size_t i = 0; i < vec.size(); i++) {
		for (size_t k = 0; k < vec.size(); k++) {
			if (vec.at(i) - vec.at(k) > distance)
				distance = vec.at(i) - vec.at(k);
		}
	}
	return distance;
}
