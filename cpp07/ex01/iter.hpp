#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void printFactor(T &factor)
{
	std::cout << factor << std::endl; 
}

template <typename T>
void iter(T* arr, size_t size, void (*f)(T&))
{
	for (size_t i = 0; i < size; i++)
		(*f)(arr[i]);
}
#endif