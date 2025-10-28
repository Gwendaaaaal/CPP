#include "Form.hpp"

Form::Form(const std::string &name, int minGradeToSign, int minGradeToExecute) : name(name), isSigned(false), minGradeToSign(minGradeToSign), minGradeToExecute(minGradeToExecute)
{
	if (minGradeToSign < 1 || minGradeToExecute < 1)
		throw GradeTooHighException();
	else if (minGradeToSign > 150 || minGradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), minGradeToSign(other.minGradeToSign), minGradeToExecute(other.minGradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
	if (this!= &other)
	{
		this->isSigned = other.isSigned;
	}
	return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const 
{
	return (this->name);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

int Form::getMinGradeToSign() const
{
	return (this->minGradeToSign);
}

int Form::getMinGradeToExecute() const
{
	return (this->minGradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureau)
{
	if (bureau.getGrade() > this->minGradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << form.getName() << " is signed : " << form.getIsSigned() << ", minimum grade to sign is : " << form.getMinGradeToSign() << ", minimum grade to execute is : " << form.getMinGradeToExecute();
	return out;
}
