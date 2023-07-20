#include "./WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongcat)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = wrongcat;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongcat)
{
	if (this != &wrongcat)
	{
		this->type = wrongcat.type;
	}
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat: mew mew..." << std::endl;
}