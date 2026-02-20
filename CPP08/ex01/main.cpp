#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "=== BASIC TEST ===" << std::endl;

    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    std::cout << "\n=== EXCEPTION TEST (capacity) ===" << std::endl;
    try {
        sp.addNumber(42);
    }
    catch (const std::exception&) {
        std::cout << "Correctly caught capacity overflow" << std::endl;
    }

    std::cout << "\n=== EXCEPTION TEST (not enough elements) ===" << std::endl;
    try {
        Span sp2(5);
        sp2.addNumber(1);
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception&) {
        std::cout << "Correctly caught span error (<2 elements)" << std::endl;
    }

    std::cout << "\n=== LARGE TEST (10 000 numbers) ===" << std::endl;

    const int SIZE = 10000;
    Span big(SIZE);

    std::vector<int> data;
    data.reserve(SIZE);

    std::srand(std::time(NULL));
    for (int i = 0; i < SIZE; ++i)
        data.push_back(std::rand());

    try {
        big.addRange(data.begin(), data.end());
        std::cout << "Shortest span (big): " << big.shortestSpan() << std::endl;
        std::cout << "Longest span (big): " << big.longestSpan() << std::endl;
    }
    catch (const std::exception&) {
        std::cout << "Error in big test" << std::endl;
    }

    std::cout << "\n=== DUPLICATE TEST ===" << std::endl;
    Span dup(3);
    dup.addNumber(5);
    dup.addNumber(5);
    dup.addNumber(10);

    std::cout << "Shortest span (duplicates): "
              << dup.shortestSpan() << std::endl;

    return 0;
}
