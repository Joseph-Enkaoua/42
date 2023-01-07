#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    _fixed_point_num = 0;
}

Fixed::Fixed( const Fixed & other ){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed( const int num ){
    std::cout << "Int constructor called" << std::endl;
	_fixed_point_num = num << _fractional_bits;
}

Fixed::Fixed( const float num ){
    std::cout << "Float constructor called" << std::endl;
	_fixed_point_num = (round(num * (1 << _fractional_bits)));
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=( const Fixed & rhs ){
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixed_point_num = rhs._fixed_point_num;
    return *this;
}

bool	Fixed::operator>(const Fixed & rhs) const {
    return (this->_fixed_point_num > rhs._fixed_point_num);
}

bool	Fixed::operator<(const Fixed & rhs) const {
    float	right = rhs.to_Float();
    float	left = this->to_Float();
    return (left < right);
}

bool	Fixed::operator>=(const Fixed & rhs) const {
    float	right = rhs.to_Float();
    float	left = this->to_Float();
    return (left >= right);
}

bool	Fixed::operator<=(const Fixed & rhs) const {
    float	right = rhs.to_Float();
    float	left = this->to_Float();
    return (left <= right);
}

bool	Fixed::operator==(const Fixed & rhs) const {
    float	right = rhs.to_Float();
    float	left = this->to_Float();
    return (left == right);
}

bool	Fixed::operator!=(const Fixed & rhs) const {
    float	right = rhs.to_Float();
    float	left = this->to_Float();
    return (left != right);
}

Fixed	Fixed::operator+(const Fixed & rhs) const{
	return (Fixed(this->to_Float() + rhs.to_Float()));
}

Fixed	Fixed::operator-(const Fixed & rhs) const{
	return (Fixed(this->to_Float() - rhs.to_Float()));
}

Fixed	Fixed::operator*(const Fixed & rhs) const{
	return (Fixed(this->to_Float() * rhs.to_Float()));
}

Fixed	Fixed::operator/(const Fixed & rhs) const {
    if (rhs.to_Float() == 0) {
        std::cout << "Devision by 0 is not possible" << std::endl;
        Fixed f(0);
        return f;
    }
	return (Fixed(this->to_Float() / rhs.to_Float()));
}

Fixed	Fixed::operator++(int){
    Fixed	tmp = *this;

	this->_fixed_point_num++;
	return (tmp);
}

Fixed	&Fixed::operator++(void){
	_fixed_point_num++;
	return (*this);
}

Fixed	Fixed::operator--(int){
	Fixed	tmp = *this;

	this->_fixed_point_num--;
	return (tmp);
}

Fixed	&Fixed::operator--(void){
	_fixed_point_num--;
	return (*this);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b){
    if (a < b)
        return (a);
    return (b);
}

Fixed const	&Fixed::min(const Fixed &a, const Fixed &b){
    if (a < b)
        return (a);
    return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b){
    if (a > b)
        return (a);
    return (b);
}

Fixed const	&Fixed::max(const Fixed &a, const Fixed &b){
    if (a > b)
        return (a);
    return (b);
}

float	Fixed::to_Float( void ) const {
	return ((double)_fixed_point_num / (double(1 << _fractional_bits)));
}

int		Fixed::toInt( void ) const {
	return (_fixed_point_num / (1 << _fractional_bits));
}

int	Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixed_point_num);
}

void	Fixed::setRawBits( int const raw ){
    std::cout << "setRawBits member function called" << std::endl;
    _fixed_point_num = raw;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &tmp){
	out << tmp.to_Float();
	return (out);
}