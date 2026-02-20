#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

	Array<std::string> strings(10);
	for (int i = 0; i < 10; i++)
	{
		std::string str;
		for (int x = 0; x < (rand() % 5 + 2); x++)
			str += 'a' + rand() % 26;
		strings[i] = str;
	}
	for (int i = 0; i < 10; i++)
	{
	  std::cout << strings[i] << std::endl;
	}
	try
	{
		std::cout << "index access : " << strings[10] << std::endl;
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
    delete [] mirror;//
    return 0;
}
