#include "PmergeMe.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <ctime>
#include <sys/time.h>

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::string nbr;
	

	for (int i = 1; i < argc; i++) 
	{
		std::string str(argv[i]);
		for (size_t ind = 0; ind < str.size(); ind++)
		{
			if (!isdigit(str[ind]) && (ind != 0 || str[ind] != '+'))
				throw std::exception();
		}
		std::stringstream ss(str);
		int value;
		ss >> value;
		if (!ss.eof() || ss.fail())
				throw std::exception();
		if (std::find(_vect.begin(), _vect.end(), value) != _vect.end())
			throw std::exception();
		_vect.push_back(value);
		_deq.push_back(value);
	}
}

PmergeMe::PmergeMe(const PmergeMe &other) : _vect(other._vect), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other)
		return *this;
	_deq = other._deq;
	_vect = other._vect;
	return (*this);
}

PmergeMe::~PmergeMe() {}

//NOTE: VECTOR PART

void PmergeMe::print_vector(std::vector<int> vect)
{
	for (size_t i = 0; i < vect.size(); i++)
	{
	  std::cout << vect[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sort_pairs(std::vector<int> &vect)
{
	int tmp;
	for (size_t i = 1; i < vect.size(); i += 2)
	{
		if (vect[i - 1] > vect[i])
		{
	  		tmp = vect[i];
			vect[i] = vect[i - 1];
			vect[i - 1] = tmp;
		}
	}
}

void PmergeMe::binaryInsert(int value, std::vector<int> &vect, int lowbound, int upbound)
{
	int middle = (lowbound + upbound) / 2;

	if (lowbound >= upbound)
	{
		if (value > vect[lowbound])
		{
			vect.insert(vect.begin() + lowbound + 1, value);
			return;
		}
		vect.insert(vect.begin() + lowbound, value);
		return ;
	}
	if (vect[middle] > value)
		return (binaryInsert(value, vect, lowbound, middle - 1));
	else if (vect[middle] < value)
		return (binaryInsert(value, vect, middle + 1, upbound));
}

std::vector<int> PmergeMe::sort_vector(std::vector<int> &vectBase)
{
	int jacobsthal[] ={1,3,5,11,21,43,85,171,341,683,1365,2731,5461,10923,21845,43691,87381};
	int inserted = 1;
	std::vector<int> bigs;
	std::vector<int> vectRes;
	if (vectBase.size() < 2)
		return vectBase;

	// Sort every pairs in the vector
	sort_pairs(vectBase);
	if (vectBase.size() == 2)
		return vectBase;
	
	// Put every big number of each pairs into bigs vector.
	for (size_t i = 1; i < vectBase.size(); i += 2)
		bigs.push_back(vectBase[i]);

	// Recursion
	std::vector<int> vectRec = sort_vector(bigs);

	vectRes = vectRec;
	// Insert first element 
	vectRes.insert(vectRes.begin(), *(std::find(vectBase.begin(), vectBase.end(), vectRec[0]) - 1));
	// 3 2 5 4 11 10 9 8 7 6 21 20 19 18 17 16 15 14 13 12 
	// 2 1 4 3 10 9 8 7 6 5 
	for (int i = 1; jacobsthal[i] < (int) vectBase.size(); i++)
	{
		for (int index = jacobsthal[i] - 1; index >= jacobsthal[i - 1]; index--)
		{
			if (index >= (int) vectRec.size())
				index = vectRec.size() - 1;
			binaryInsert(*(std::find(vectBase.begin(), vectBase.end(), vectRec[index]) - 1), vectRes, 0, inserted + index);
			inserted++;
		}
	}
	
	if (vectBase.size() % 2)
		binaryInsert(*(vectBase.end()-1), vectRes, 0, vectRes.size() - 1);
	return (vectRes);
}

//NOTE: deque part

void PmergeMe::print_deque(std::deque<int> vect)
{
	for (size_t i = 0; i < vect.size(); i++)
	{
	  std::cout << vect[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sort_pairs(std::deque<int> &vect)
{
	int tmp;
	for (size_t i = 1; i < vect.size(); i += 2)
	{
		if (vect[i - 1] > vect[i])
		{
	  		tmp = vect[i];
			vect[i] = vect[i - 1];
			vect[i - 1] = tmp;
		}
	}
}

void PmergeMe::binaryInsert(int value, std::deque<int> &vect, int lowbound, int upbound)
{
	int middle = (lowbound + upbound) / 2;

	if (lowbound >= upbound)
	{
		if (value > vect[lowbound])
		{
			vect.insert(vect.begin() + lowbound + 1, value);
			return;
		}
		vect.insert(vect.begin() + lowbound, value);
		return ;
	}
	if (vect[middle] > value)
		return (binaryInsert(value, vect, lowbound, middle - 1));
	else if (vect[middle] < value)
		return (binaryInsert(value, vect, middle + 1, upbound));
}

std::deque<int> PmergeMe::sort_deque(std::deque<int> &vectBase)
{
	int jacobsthal[] ={1,3,5,11,21,43,85,171,341,683,1365,2731,5461,10923,21845,43691,87381};
	int inserted = 1;
	std::deque<int> bigs;
	std::deque<int> vectRes;
	if (vectBase.size() < 2)
		return vectBase;

	// Sort every pairs in the deque
	sort_pairs(vectBase);
	if (vectBase.size() == 2)
		return vectBase;
	
	// Put every big number of each pairs into bigs deque.
	for (size_t i = 1; i < vectBase.size(); i += 2)
		bigs.push_back(vectBase[i]);

	// Recursion
	std::deque<int> vectRec = sort_deque(bigs);

	vectRes = vectRec;
	// Insert first element 
	vectRes.insert(vectRes.begin(), *(std::find(vectBase.begin(), vectBase.end(), vectRec[0]) - 1));
	// 3 2 5 4 11 10 9 8 7 6 21 20 19 18 17 16 15 14 13 12 
	// 2 1 4 3 10 9 8 7 6 5 
	for (int i = 1; jacobsthal[i] < (int) vectBase.size(); i++)
	{
		for (int index = jacobsthal[i] - 1; index >= jacobsthal[i - 1]; index--)
		{
			if (index >= (int) vectRec.size())
				index = vectRec.size() - 1;
			binaryInsert(*(std::find(vectBase.begin(), vectBase.end(), vectRec[index]) - 1), vectRes, 0, inserted + index);
			inserted++;
		}
	}
	
	if (vectBase.size() % 2)
		binaryInsert(*(vectBase.end()-1), vectRes, 0, vectRes.size() - 1);
	return (vectRes);
}

int PmergeMe::pmergeme()
{
	std::cout << "Before:	";
	print_vector(_vect);
	std::clock_t start = std::clock();
	_vect = sort_vector(_vect);
	std::clock_t end = std::clock();
	double vect_duration = double(end - start) / CLOCKS_PER_SEC * 1000000;

	start = std::clock();
	_deq = sort_deque(_deq);
	end = std::clock();
	double deque_duration = double(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After:	";
	print_vector(_vect);

	std::cout << "Time with vector : " << vect_duration << "μs" << std::endl;
	std::cout << "Time with deque : " << deque_duration << "μs" << std::endl;
	// std::cout << " elements with std::vect : " << std::setprecision(10) << elapsed_time << " μs.\n\n";
	return (0);
}
