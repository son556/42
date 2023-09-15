#include "easyfind.hpp"

int main(void)
{
	std::vector<int> arr;
	for (int i = 0; i < 5; i++)
		arr.push_back(i);
	std::vector<int>::iterator idx = easyfind(arr, 3);
	std::cout << "val: " << *idx << std::endl;
	try
	{
		idx = easyfind(arr, 10);
		std::cout << "idx_fail: " << *idx << std::endl;
	}
	catch(const char *str)
	{
		std::cerr << "vector: " << str << '\n';
	}
	
	std::list<int> l;
	for (int i = 0; i < 5; i++)
		l.push_back(i + 1);
	l.begin();
	std::list<int>::iterator ldx = easyfind(l, 2);
	std::cout << "idx_l: " << *ldx << std::endl;
	try
	{
		ldx = easyfind(l, 0);
		std::cout << "idx_l: " << *ldx << std::endl;
	}
	catch(const char *str)
	{
		std::cerr << "list: " << str << '\n';
	}
}