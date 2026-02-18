#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
	AForm* rrf;
	Intern someRandomIntern;
	Bureaucrat bigboss("Boss", 1);
	{
		std::cout << std::endl << "---------- ROBOTOMY REQUEST FORM -------------------" << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		bigboss.signForm(*rrf);
		bigboss.executeForm(*rrf);
		delete rrf;
	}
	{
		std::cout << std::endl << "---------- SHRUBBERY CREATION FORM ------------------" << std::endl;
		rrf = someRandomIntern.makeForm("shrubbery creation", "garden");
		bigboss.signForm(*rrf);
		bigboss.executeForm(*rrf);
		delete rrf;
	}
	{
		std::cout << std::endl << "---------- PRESIDENTIAL PARDON FORM -----------------" << std::endl;
		rrf = someRandomIntern.makeForm("presidential pardon", "Marc");
		bigboss.signForm(*rrf);
		bigboss.executeForm(*rrf);
		delete rrf;
	}
	{
		std::cout << std::endl << "---------- BAD FORM NAME ----------------------------" << std::endl;
		rrf = someRandomIntern.makeForm("bad request", "Target");
	}
	return (0);
}
