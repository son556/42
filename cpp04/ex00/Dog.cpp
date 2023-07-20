#include "./Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const std::string &type)
{
	this->type = type;
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& dog)
{
	*this = dog;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
	if (this != &dog)
	{
		this->type = dog.type;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "bark bark!!" << std::endl;
}
