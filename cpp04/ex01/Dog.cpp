#include "./Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->br = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const std::string &type)
{
	this->type = type;
	this->br = new Brain();
	std::cout << "Dog constructor(type) called" << std::endl;
}

Dog::Dog(const Dog& dog)
{
	*this = dog;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::Dog(const Brain &brain)
{
	std::cout << "Dog constructor(brain) called" << std::endl;
	this->type = "Dog";
	this->br = new Brain(brain);
}

Dog::~Dog()
{
	delete br;
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& dog)
{
	if (this != &dog)
	{
		this->br = new Brain(*(dog.br));
		this->type = dog.type;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "bark bark!!" << std::endl;
}
