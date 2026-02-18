#include "Span.hpp"

Span::Span() : _max(10) {}

Span::Span(unsigned int N) : _max(N) {}

Span::Span(const Span &other) : _vect(other._vect), _max(other._max) {}

Span& Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	_vect = other._vect;
	_max = other._max;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num)
{
	if (_vect.size() >= _max)
	{
		throw std::exception();
	}
	_vect.push_back(num);
}

int Span::shortestSpan() const
{
	int min, sub;

	if (_vect.size() < 2)
		throw std::exception();
	std::vector<int> tmp(_vect);
	
	std::sort(tmp.begin(), tmp.end());

	min = tmp[1] - tmp[0];
	for (size_t i = 2; i < tmp.size(); i++)
	{
		sub = tmp[i] - tmp[i - 1];
		if (sub < min)
			min = sub;
	}
	return min;
}

int Span::longestSpan() const
{
	if (_vect.size() < 2)
		throw std::exception();

	return (*std::max_element(_vect.begin(), _vect.end()) - *std::min_element(_vect.begin(), _vect.end()));
}

void Span::addRange(int range)
{
	if (_vect.size() + range >= _max)
		throw std::exception();

}
