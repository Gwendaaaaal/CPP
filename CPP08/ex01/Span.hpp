#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <exception>
#include <vector>

class Span {
private:
	unsigned int _max;
	std::vector<int> _vect;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span& operator=(const Span &other);
	~Span();

	void addNumber(int num);
	int shortestSpan() const;
	int longestSpan() const;


	template <typename T>
	void addRange(T first, T last)
	{
		if (std::distance(first, last) + _vect.size() > _max)
			throw std::exception();
		_vect.insert(_vect.end(), first, last);
	}
};

#endif
