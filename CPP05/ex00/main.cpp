#include "Bureaucrat.hpp"

int main()
{
	try 
	{
        Bureaucrat bob("Bob", 151);
    } 
	catch (const std::exception &e) 
	{
        std::cerr << e.what() << std::endl;
    }

	std::cout << "----------------" << std::endl;

	try 
	{
		Bureaucrat alice("Alice", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "----------------" << std::endl;

	Bureaucrat john("John", 150);
	std::cout << john << std::endl;
	try 
	{
		john.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << john << std::endl;;
	try 
	{
		john.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << john << std::endl;;

	std::cout << "----------------" << std::endl;

	Bureaucrat marc("Marc", 1);
	std::cout << marc << std::endl;
	try 
	{
		marc.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << marc << std::endl;;
	try 
	{
		marc.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << marc << std::endl;;
}
