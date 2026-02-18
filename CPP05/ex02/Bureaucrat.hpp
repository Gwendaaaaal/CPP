#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class AForm;

class Bureaucrat {
private:
	std::string name;
	int			grade;

public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	class GradeTooHighException : public std::exception 
	{
	public:
		virtual const char* what() const throw() 
		{
			return "Bureaucrat grade too high";
		}
	};
	class GradeTooLowException : public std::exception 
	{
	public:
		virtual const char* what() const throw() 
		{
			return "Bureaucrat grade too low";
		}
	};

	std::string	getName() const;
	int			getGrade() const;

	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &form);
	void executeForm(AForm const &form) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureau);

#endif
