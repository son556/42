#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <stdint.h>

typedef struct Data
{
	int a;
}	Data;

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer& ref);
		~Serializer();
		Serializer&	operator=(const Serializer& ref);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t& ref);
};

#endif