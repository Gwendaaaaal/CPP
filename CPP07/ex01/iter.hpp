#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T* array, const size_t size, void (*f)(T&))
{
	if (!array || !f)
		return ;
	for (size_t i = 0; i < size; ++i)
		f(array[i]);
}

template <typename T>
void iter(T* array, const size_t size, void (*f)(T const&))
{
	if (!array || !f)
		return ;
	for (size_t i = 0; i < size; ++i)
		f(array[i]);
}

template <typename T>
void iter(T const* array, const size_t size, void (*f)(T const&))
{
	if (!array || !f)
		return ;
	for (size_t i = 0; i < size; ++i)
		f(array[i]);
}
#endif
