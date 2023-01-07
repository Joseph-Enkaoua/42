#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>
#include <ctime>

template < typename T > class Array {
private:
	T				*var;
	unsigned int	s;
public:
	Array() : var(new T[0]), s(0) {}
	Array(unsigned int n) : var(new T[n]), s(n) {
		if (n > 0) {
			bzero(var, n);
		} else {
			std::cerr << "Error: size must be bigger than 0" << std::endl;
		}
	}
	~Array() { delete[] var; }
	Array(const Array &other) : var(new T[other.s]), s(other.s) {
		for (int i = 0;i < (int)s;i++){
			this->var[i] = other.var[i];
		}
	}
	Array & operator=(const Array<T> &rhs) {
		if (*this == rhs)
			return *this;
		delete[] var;
		var = Array(rhs);
		return *this;
	}
	T	& operator[](unsigned int n) {
		if (n >= s)
			throw Array::OutOfRangeException();
		return (var[n]);
	}
	unsigned int	size(){ return s; }

    class OutOfRangeException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return ("Error: no value found");
        }
    };
};

//for testing
template < typename T > void printArray(Array<T>& arr, unsigned int length)
{
	for (unsigned int i = 0; i < length; i++)
		std::cout << arr[i] << " ";
}

template < typename T > void printTypeArray(T& arr, unsigned int length)
{
	for (unsigned int i = 0; i < length; i++)
		std::cout << arr[i] << " ";
}

#endif