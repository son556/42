#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	arr = new T();
	cnt = 1;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	arr = new T[n];
	cnt = n;
}

template <typename T>
Array<T>::Array(const Array& ref)
{
	arr = new T();
	cnt = 1;
	*this = ref;
}

template <typename T>
Array<T>::~Array()
{
	if (cnt == 1)
		delete arr;
	else
		delete[] arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& ref)
{
	if (this->cnt > 1)
		delete[] arr;
	else
		delete arr;
	arr = new T[ref.cnt];
	cnt = ref.cnt;
	for (size_t i = 0; i < ref.cnt; i++)
		arr[i] = ref.arr[i];
	return *this;
}

template <typename T>
T& Array<T>::operator[](size_t idx) const
{
	try
	{
		std::cout << "const operator excute...." << std::endl;
		if (idx >= cnt || idx < 0)
			throw std::out_of_range("index Out of Range!");
		return arr[idx];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	};
	return arr[idx];
}

template <typename T>
T& Array<T>::operator[](size_t idx)
{
	try
	{
		std::cout << "operator excute..." << std::endl;
		if (idx >= cnt || idx < 0)
			throw std::out_of_range("index Out of Range!");
		return arr[idx];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return arr[idx];
}

template <typename T>
size_t Array<T>::size() const
{
	return cnt;
}
