#ifndef FIXED_HPP
# define FIXED_HPP
# include <string>
# include <iostream>
# include <cmath>

class Fixed {
private:
    int 				_fixed_point_num;
    static const int	_fractional_bits = 8;
public:
	Fixed();
	Fixed( const Fixed & other );
	Fixed( const int num );
	Fixed( const float num );
	~Fixed();

	Fixed & operator=(const Fixed & fixed);
    
    int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	to_Float( void ) const;
    int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &tmp);

#endif
