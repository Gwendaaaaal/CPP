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
    size_t lenA = sizeof(a) / sizeof(a[0]);

    std::cout << "Print int array:" << std::endl;
    iter(a, lenA, printElem<int>);

    std::cout << "Increment int array:" << std::endl;
    iter(a, lenA, increment);
    iter(a, lenA, printElem<int>);

    std::string s[] = {"salut", "42", "templates"};
    size_t lenS = sizeof(s) / sizeof(s[0]);

    std::cout << "Print string array:" << std::endl;
    iter(s, lenS, printElem<std::string>);

    const int ca[] = {10, 20, 30};
    size_t lenCA = sizeof(ca) / sizeof(ca[0]);

    std::cout << "Print const int array:" << std::endl;
    iter(ca, lenCA, printElem<int>);

    // iter(ca, lenCA, increment);

    return 0;
}
