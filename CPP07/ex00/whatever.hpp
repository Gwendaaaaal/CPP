#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& A, T& B)
{
	T tmp = A;
	A = B;
	B = tmp;
}

template <typename T>
const T& min(const T& A, const T& B)
{
	if (A < B)
		return A;
	return B;
}

template <typename T>
const T& max(const T& A, const T& B)
{
	if (A > B)
		return A;
	return B;
}

#endif
