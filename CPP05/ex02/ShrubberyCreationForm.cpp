#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberryCreationForm::ShrubberryCreationForm(const std::string &target) : AForm("ShrubberyCreation", 145, 137), _target(target) {}

ShrubberryCreationForm::ShrubberryCreationForm(const ShrubberryCreationForm &other) : AForm(other), _target(other._target) {}

ShrubberryCreationForm& ShrubberryCreationForm::operator=(const ShrubberryCreationForm& other) 
{
	if (this != &other)
		this->_target = other._target;
	return *this;
}

ShrubberryCreationForm::~ShrubberryCreationForm() {}

void ShrubberryCreationForm::doExecute() const
{
	std::ofstream file((this->_target + "_shrubberry").c_str());
	if (!file.is_open()) 
	{
		std::cerr << "Error with opening file " << this->_target << "_shrubberry" << std::endl;
	}
    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      /\\\\/ \\\n";
	file.close();
}
