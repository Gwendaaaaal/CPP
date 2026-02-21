#include "BitcoinExchange.hpp"
#include <iomanip>

static std::string trim(const std::string& str)
{
    std::string s = str;

    std::size_t start = s.find_first_not_of(" \t");
    if (start == std::string::npos)
        return "";

    std::size_t end = s.find_last_not_of(" \t");

    return s.substr(start, end - start + 1);
}

static int parseData(std::map<std::string, double>& map, std::ifstream& data)
{
	std::string line;

	while (std::getline(data,line))
	{
		if (line.empty())
			continue;
		
		if (line == "date,exchange_rate")
			continue;

		std::size_t comma = line.find(',');

		if (comma == std::string::npos)
		{
			std::cerr << "Couldn't parse line : " << line << std::endl;
			return (1);
		}

		std::string date = line.substr(0, comma);
		std::string value = line.substr(comma + 1);

		std::stringstream ss(value); 
		double rate;
		ss >> rate;

		if (ss.fail() || !ss.eof())
		{
			std::cerr << "Couldn't parse value : " << value << std::endl;
			return (1);
		}
		map[date] = rate;
	}
	return (0);
}

static bool isValidDate(const std::string& date)
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    for (int i = 0; i < 4; i++)
        if (!std::isdigit(yearStr[i]))
            return false;

    for (int i = 0; i < 2; i++)
        if (!std::isdigit(monthStr[i]) || !std::isdigit(dayStr[i]))
            return false;

    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > 31)
        return false;

    return true;
}

static bool isValidValue(const std::string& str, double& out)
{
    if (str.empty())
        return false;

    std::stringstream ss(str);
    ss >> out;

    if (ss.fail() || !ss.eof())
        return false;

    return true;
}

static bool getRate(const std::map<std::string, double>& rates, const std::string& date, double& rate)
{
    std::map<std::string, double>::const_iterator it = rates.lower_bound(date);

    if (it != rates.end() && it->first == date)
    {
        rate = it->second;
        return true;
    }

    if (it == rates.begin())
        return false;

    --it;
    rate = it->second;
    return true;
}

static int parseInput(std::map<std::string, double>& map, std::ifstream& input)
{
	std::string line;

	while (getline(input, line))
	{
		if (line.empty())
			continue;

		if (line == "date | value")
			continue;

		std::size_t split = line.find('|');
		if (split == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, split));
		std::string valueStr = trim(line.substr(split + 1));

		if (date.empty() || valueStr.empty())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		double value;
		if (!isValidValue(valueStr, value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		double rate;
		if (!getRate(map, date, rate))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::cout << std::fixed << std::setprecision(2) << std::endl;
		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}
	return (0);
}

int BitcoinExchange(const std::string& filename)
{
	std::map<std::string, double> map;
	std::ifstream data("data.csv");
	std::ifstream input(filename.c_str());

	if (!data.is_open() || !input.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	if (parseData(map, data))
		return (1);

	if (parseInput(map, input))
		return (1);
	
	return (0);
}
