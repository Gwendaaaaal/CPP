#include "Base.hpp"

int main(void)
{
	std::srand(std::time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base* ptr = generate();
		identify(ptr);
		identify(*ptr);
		std::cout << std::endl;
		delete ptr;
	}
}
