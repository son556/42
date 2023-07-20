#include "./Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called" << std::endl;
}

Animal::Animal(const Animal& ani)
{
	std::cout << "Animal copy constructal called" << std::endl;
	*this = ani;
}

Animal& Animal::operator=(const Animal& ani)
{
	if (this != &ani)
	{
		this->type = ani.type;
	}
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}