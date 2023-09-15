#include "iter.hpp"

int main()
{
	int arr[5] = {2, 1, 5, 4, 3};
	std::string s_arr[5] = {"b", "a", "e", "d", "c"};

	iter<int>(arr, 5, printFactor);
	iter<std::string>(s_arr, 5, printFactor);
}
