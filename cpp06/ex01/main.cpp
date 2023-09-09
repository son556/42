#include "Serialization.hpp"

int main(void)
{
	Data		origin_data;
	Data		*new_data;
	uintptr_t	t;

	t = Serializer::serialize(&origin_data);
	new_data = Serializer::deserialize(t);
	std::cout << &origin_data << std::endl;
	std::cout << new_data << std::endl;
}