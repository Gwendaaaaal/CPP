#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) 
{
	(void) other;
}

Intern& Intern::operator=(const Intern &other) 
{
	(void) other;
	if (this == &other)
		return *this;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeShrubberry(const std::string target)
{
	return new ShrubberryCreationForm(target);
}
AForm* Intern::makeRobotomy(const std::string target)
{
	return new RobotomyRequestForm(target);
}
AForm* Intern::makePresidential(const std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*forms[3])(const std::string) = {&Intern::makeShrubberry, &Intern::makeRobotomy, &Intern::makePresidential};
	
	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*forms[i])(target);
		}
	}
	std::cout << "Unknown form name : " << name << std::endl;
	return NULL;
}
