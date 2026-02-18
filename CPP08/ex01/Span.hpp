#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <vector>
#include <exception>

class Span {
private:
	std::vector<int> _vect;
	unsigned int _max;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span& operator=(const Span &other);
	~Span();

	void addNumber(int num);
	int shortestSpan() const;
	int longestSpan() const;

	void addRange(int range);

};

#endif
