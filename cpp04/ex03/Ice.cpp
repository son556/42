#include "./Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice(const Ice& ice)
{
	*this = ice;
}

Ice::~Ice()
{
}

Ice& Ice::operator=(const Ice& ice)
{
	if (this != &ice)
		this->type = ice.type;
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "Ice:\"* shoots an ice bolt at \"" << target.getName() << " *" << std::endl;
}