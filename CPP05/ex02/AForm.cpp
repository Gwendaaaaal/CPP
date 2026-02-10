#include "AForm.hpp"

AForm::AForm(const std::string &name, int minGradeToSign, int minGradeToExecute) : name(name), isSigned(false), minGradeToSign(minGradeToSign), minGradeToExecute(minGradeToExecute)
{
	if (minGradeToSign < 1 || minGradeToExecute < 1)
		throw GradeTooHighException();
	else if (minGradeToSign > 150 || minGradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), minGradeToSign(other.minGradeToSign), minGradeToExecute(other.minGradeToExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this!= &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getName() const 
{
	return (this->name);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

int AForm::getMinGradeToSign() const
{
	return (this->minGradeToSign);
}

int AForm::getMinGradeToExecute() const
{
	return (this->minGradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureau)
{
	if (bureau.getGrade() > this->minGradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

void AForm::execute(Bureaucrat const & executor)
{
	if (!this->isSigned)
		throw FormIsNotSigned();
	if (executor.getGrade() > this->minGradeToExecute)
		throw GradeTooLowException();
	doExecute();
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	out << form.getName() << " is signed : " << form.getIsSigned() << ", minimum grade to sign is : " << form.getMinGradeToSign() << ", minimum grade to execute is : " << form.getMinGradeToExecute();
	return out;
}
