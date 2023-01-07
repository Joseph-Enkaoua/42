#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    _fixed_point_num = 0;
}

Fixed::Fixed(const Fixed & other){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed & Fixed::operator=(const Fixed & rhs){
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixed_point_num = rhs._fixed_point_num;
    return (*this);
}

int	Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixed_point_num);
}

void	Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    _fixed_point_num = raw;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}
