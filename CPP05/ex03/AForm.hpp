#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>


class AForm {
private:
	const std::string	name;
	bool				isSigned;
	const int			minGradeToSign;
	const int			minGradeToExecute;

	virtual void doExecute() const = 0;

public:
	AForm(const std::string &name, const int minGradeToSign, const int minGradeToExecute);
	AForm(const AForm &other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	class GradeTooHighException : public std::exception 
	{
	public:
		virtual const char* what() const throw() 
		{
			return "grade too high";
		}
	};
	class GradeTooLowException : public std::exception 
	{
	public:
		virtual const char* what() const throw() 
		{
			return "grade too low";
		}
	};
	class FormIsSigned : public std::exception 
	{
	public:
		virtual const char* what() const throw() 
		{
			return "form is signed";
		}
	};
	class FormIsNotSigned : public std::exception 
	{
	public:
		virtual const char* what() const throw() 
		{
			return "form is not signed";
		}
	};

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getMinGradeToSign() const;
	int			getMinGradeToExecute() const;

	void beSigned(const Bureaucrat &bureau);
	void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
