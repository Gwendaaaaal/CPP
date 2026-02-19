#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElem(T const& x)
{
    std::cout << x << std::endl;
}

void increment(int& x)
{
    ++x;
}

int main()
{
    int a[] = {1, 2, 3, 4};

    std::cout << "Print int array:" << std::endl;
    iter(a, 4, printElem<int>);

    std::cout << "Increment int array:" << std::endl;
    iter(a, 4, increment);
    iter(a, 4, printElem<int>);

    std::string s[] = {"abc", "123", "xyz"};

    std::cout << "Print string array:" << std::endl;
    iter(s, 3, printElem<std::string>);

    const int ca[] = {10, 20, 30};

    std::cout << "Print const int array:" << std::endl;
    iter(ca, 3, printElem<int>);

	// increment non const avec array const : ne compile pas
    // iter(ca, lenCA, increment);

    return 0;
}
