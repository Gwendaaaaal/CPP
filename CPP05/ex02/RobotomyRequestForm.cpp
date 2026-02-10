#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <climits>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequest", 72, 45), _target(target)
{
	srand(clock() % INT_MAX);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) 
{
	if (this != &other)
		this->_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::doExecute() const
{
	int i = rand();
	std::cout << "drrrrrrrrrrrrr" << std::endl;

	if (i % 2)
		std::cout << _target << " has been lobotomized successfully." << std::endl;
	else
		std::cout << _target << " has sadly not been lobotomized." << std::endl;

}
