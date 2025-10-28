#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat bob("Bob", 125);
	Form a("A", 130, 100);
	Form b("B", 100, 100);

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	bob.signForm(a);
	bob.signForm(b);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
}
