#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>


class Form {
private:
	const std::string	name;
	bool				isSigned;
	const int			minGradeToSign;
	const int			minGradeToExecute;

public:
	Form(const std::string &name, const int minGradeToSign, const int minGradeToExecute);
	Form(const Form &other);
	Form& operator=(const Form& other);
	~Form();

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

	std::string	getName() const;
	bool		getIsSigned() const;
	int			getMinGradeToSign() const;
	int			getMinGradeToExecute() const;

	void beSigned(const Bureaucrat &bureau);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
