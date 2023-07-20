#include "./AMateria.hpp"

AMateria::AMateria(std::string const& type)
{
	this->type = type;
}

AMateria::AMateria()
{
	type = "nothing";
}

AMateria::AMateria(const AMateria& am)
{
	type = am.type;
}

AMateria &AMateria::operator=(const AMateria &am)
{
	type = am.type;
	return (*this);
}

AMateria::~AMateria()
{
}

const std::string& AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& ic)
{
	std::cout << "AMateria use(ICharector&)" << ic.getName() << " called" << std::endl;
}