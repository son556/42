#include "./Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->br = new Brain();
}

Cat::Cat(const std::string &type)
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = type;
	this->br = new Brain();
}

Cat::Cat(const Cat& cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cat;
}

Cat::Cat(const Brain& brain)
{
	std::cout << "Cat constructor(brain) called" << std::endl;
	this->br = new Brain(brain);
	this->type = "Cat";
}

Cat::~Cat()
{
	delete br;
	std::cout << "Cat destructor called" << std::endl;
}


Cat& Cat::operator=(const Cat& cat)
{
	if (this != &cat)
	{
		this->br = new Brain(*(cat.br));
		this->type = cat.type;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "mew mew..." << std::endl;
}
