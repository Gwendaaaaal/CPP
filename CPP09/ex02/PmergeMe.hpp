#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>

class PmergeMe {
private:
	std::vector<int> _vect;
	std::deque<int> _deq;

	void print_vector(std::vector<int> vect);
	void sort_pairs(std::vector<int> &vect);
	void binaryInsert(int value, std::vector<int> &vect, int lowbound, int upbound);
	std::vector<int> sort_vector(std::vector<int> &vectBase);

	void print_deque(std::deque<int> vect);
	void sort_pairs(std::deque<int> &vect);
	void binaryInsert(int value, std::deque<int> &vect, int lowbound, int upbound);
	std::deque<int> sort_deque(std::deque<int> &vectBase);
	
public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe &other);
	PmergeMe& operator=(const PmergeMe &other);
	~PmergeMe();

	int pmergeme(void);
};

#endif

