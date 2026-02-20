#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	{
		std::cout << "--- tests with mutantstack ---" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "--- tests with list ---" << std::endl;
		std::list<int> ilist;
		ilist.push_back(5);
		ilist.push_back(17);
		std::cout << ilist.back() << std::endl; 
		ilist.pop_back();
		std::cout << ilist.size() << std::endl; 
		ilist.push_back(3);
		ilist.push_back(5);
		ilist.push_back(737);
		ilist.push_back(0);
		std::list<int>::iterator it = ilist.begin();
		std::list<int>::iterator ite = ilist.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return (0);
}
