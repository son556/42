#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& wronganimal)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = wronganimal;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wronganimal)
{
	if (this != &wronganimal)
	{
		this->type = wronganimal.type;
	}
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal make sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}