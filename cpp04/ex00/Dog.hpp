#ifndef DOG_HPP
#define DOG_HPP

#include "./Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const std::string &type);
		Dog(const Dog& Dog);
		Dog& operator=(const Dog& dog);
		virtual ~Dog();
		virtual void makeSound() const;
};
#endif