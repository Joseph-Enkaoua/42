#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <vector>
# include <deque>
# include <list>

template < typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<int> {
public:
	//constructors & so
	MutantStack() {}
	MutantStack(const MutantStack &rhs) {
		this = rhs;
	}
	MutantStack& operator=(const MutantStack &rhs) {
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	//iterators
	typedef typename std::stack<T>::container_type::iterator    			iterator;
	typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

	iterator    begin() {
		return this->c.begin();
	}
	iterator    end() {
		return this->c.end();
	}
	const_iterator cbegin() const {
		return this->c.cbegin();
	}
	const_iterator cend() const {
		return this->c.cend();
	}
	reverse_iterator rbegin() {
		return this->c.rbegin();
	}
	reverse_iterator rend() {
		return this->c.rend();
	}
	const_reverse_iterator crbegin() const {
		return this->c.crbegin();
	}
	const_reverse_iterator crend() const {
		return this->c.crend();
	}
};

#endif
