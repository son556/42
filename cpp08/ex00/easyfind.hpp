#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
	typename T::iterator idx = std::find(container.begin(), container.end(), n);
	if (idx == container.end())
		throw "can't find number...";
	return idx;
}
#endif