#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>


class Fixed {
private:
	int fixed_value;
	static const int fractionals_bits;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
