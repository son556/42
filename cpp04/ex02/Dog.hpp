#ifndef DOG_HPP
#define DOG_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"

class Dog : public Animal, public Brain
{
	private:
		Brain *br;
	public:
		Dog();
		Dog(const std::string &type);
		Dog(const Dog& Dog);
		Dog(const Brain &brain);
		Dog& operator=(const Dog& dog);
		virtual ~Dog();
		virtual void makeSound() const;
};
#endif