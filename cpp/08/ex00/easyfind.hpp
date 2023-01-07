#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <iostream>
# include <vector>
# include <iterator>
# include <list>
# include <deque>

class notFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return ("Error 404: Not found");
    }
};

template < typename T >
typename T::iterator easyfind(T c, int n) {
    typename T::iterator i = std::find(c.begin(), c.end(), n);
    if (i == c.end())
        throw notFoundException();
    return i;
}

#endif