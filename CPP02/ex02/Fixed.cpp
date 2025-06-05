#include "Fixed.hpp"
#include <cmath>

static int pow(int nb, int pow)
{
	int res;

	res = nb;
	for (int i = 1; i < pow; i++)
		res *= nb;
	return (res);
}

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->fixed_value = 0;
}

Fixed::Fixed(int nb)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fixed_value = nb * pow(2, this->fractionals_bits);
}

Fixed::Fixed(float nb)
{
	// std::cout << "Float constructor called" << std::endl;
	this->fixed_value = roundf(nb * pow(2, this->fractionals_bits));
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->fixed_value = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixed_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_value);
}

void Fixed::setRawBits(const int raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->fixed_value = raw;
}

int Fixed::toInt(void) const
{
	return(this->fixed_value / pow(2, this->fractionals_bits));
}

float Fixed::toFloat(void) const
{
	return((float) this->fixed_value / pow(2, this->fractionals_bits));
}

bool Fixed::operator>(const Fixed& other) const
{
    return fixed_value > other.fixed_value;
}

bool Fixed::operator<(const Fixed& other) const 
{
    return fixed_value < other.fixed_value;
}

bool Fixed::operator>=(const Fixed& other) const 
{
    return fixed_value >= other.fixed_value;
}

bool Fixed::operator<=(const Fixed& other) const 
{
    return fixed_value <= other.fixed_value;
}

bool Fixed::operator==(const Fixed& other) const 
{
    return fixed_value == other.fixed_value;
}

bool Fixed::operator!=(const Fixed& other) const 
{
    return fixed_value != other.fixed_value;
}

Fixed Fixed::operator+(const Fixed& other) const 
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const 
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const 
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const 
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	this->fixed_value += 1;
	return *this;
}

Fixed& Fixed::operator--()
{
	this->fixed_value -= 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->fixed_value += 1;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->fixed_value -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}


std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return out;
}
