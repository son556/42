#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
template <typename T>
class Array
{
	private:
		T *arr;
		size_t cnt;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& ref);
		~Array();
		Array& operator=(const Array& ref);
		T& operator[](size_t idx) const;
		T& operator[](size_t idx);
		size_t size() const;
};
#include "Array.tpp"
#endif