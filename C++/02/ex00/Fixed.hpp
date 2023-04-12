#ifndef FIXED_HPP
# define FIXED_HPP
# include <string>
# include <iostream>

class Fixed {
private:
    int					_fixed_point_num;
    static const int	_fractional_bits = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed & operator=(const Fixed & other);
	~Fixed();
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif