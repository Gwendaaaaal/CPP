#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int to_find)
{
	typename T::iterator ret = std::find(container.begin(), container.end(), to_find);
	if (ret != container.end())
		return ret;
	throw std::exception();
}

template <typename T>
typename T::const_iterator easyfind(T const& container, int to_find)
{
	typename T::const_iterator ret = std::find(container.begin(), container.end(), to_find);
	if (ret != container.end())
		return ret;
	throw std::exception();
}

#endif
