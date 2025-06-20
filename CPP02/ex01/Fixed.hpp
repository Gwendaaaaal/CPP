#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>
#include <math.h>


class Fixed {
private:
	int fixed_value;
	static const int fractionals_bits = 8;

public:
	Fixed();
	Fixed(int nb);
	Fixed(float nb);
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif
