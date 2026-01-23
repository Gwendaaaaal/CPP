#include "ScalarConverter.hpp"

#include <climits>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

static bool	isNanValue(double value)
{
	return (value != value);
}

static bool	isInfValue(double value)
{
	return (value == std::numeric_limits<double>::infinity()
		|| value == -std::numeric_limits<double>::infinity());
}

static bool	isIntegralValue(double value)
{
	if (isNanValue(value) || isInfValue(value))
		return (false);
	return (value == std::floor(value));
}

static bool	isCharLiteral(const std::string &literal)
{
	return (literal.length() == 1
		&& !std::isdigit(static_cast<unsigned char>(literal[0])));
}

static bool	isPseudoLiteral(const std::string &literal, double &value,
		bool &isNegative, bool &isNanLiteral)
{
	isNegative = false;
	isNanLiteral = false;
	if (literal == "nan" || literal == "nanf")
	{
		value = std::numeric_limits<double>::quiet_NaN();
		isNanLiteral = true;
		return (true);
	}
	if (literal == "+inf" || literal == "+inff"
		|| literal == "inf" || literal == "inff")
	{
		value = std::numeric_limits<double>::infinity();
		return (true);
	}
	if (literal == "-inf" || literal == "-inff")
	{
		value = -std::numeric_limits<double>::infinity();
		isNegative = true;
		return (true);
	}
	return (false);
}

static bool	parseNumber(const std::string &literal, double &value)
{
	char	*end = NULL;

	value = std::strtod(literal.c_str(), &end);
	if (end == NULL || *end != '\0')
		return (false);
	return (true);
}

static void	printInvalid(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
	double	value = 0.0;
	bool	pseudo = false;
	bool	isNegativePseudo = false;
	bool	isNanPseudo = false;

	if (isCharLiteral(literal))
		value = static_cast<double>(literal[0]);
	else
	{
		std::string	number = literal;

		pseudo = isPseudoLiteral(literal, value, isNegativePseudo, isNanPseudo);
		if (!pseudo)
		{
			if (literal.length() > 1 && literal[literal.length() - 1] == 'f')
				number = literal.substr(0, literal.length() - 1);
			if (!parseNumber(number, value))
				return (printInvalid());
		}
	}
	std::cout << "char: ";
	if (pseudo || isNanValue(value) || isInfValue(value)
		|| value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	std::cout << "int: ";
	if (pseudo || isNanValue(value) || isInfValue(value)
		|| value < INT_MIN || value > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
	std::cout << "float: ";
	if (pseudo)
	{
		if (isNanPseudo)
			std::cout << "nanf" << std::endl;
		else if (isNegativePseudo)
			std::cout << "-inff" << std::endl;
		else
			std::cout << "+inff" << std::endl;
	}
	else
	{
		float	fvalue = static_cast<float>(value);

		std::cout.setf(std::ios::fixed);
		std::cout << std::setprecision(isIntegralValue(value) ? 1 : 6);
		std::cout << fvalue << "f" << std::endl;
	}
	std::cout << "double: ";
	if (pseudo)
	{
		if (isNanPseudo)
			std::cout << "nan" << std::endl;
		else if (isNegativePseudo)
			std::cout << "-inf" << std::endl;
		else
			std::cout << "+inf" << std::endl;
	}
	else
	{
		std::cout.setf(std::ios::fixed);
		std::cout << std::setprecision(isIntegralValue(value) ? 1 : 6);
		std::cout << value << std::endl;
	}
}
