#include "./Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure(const Cure& Cure)
{
	*this = Cure;
}

Cure::~Cure()
{
}

Cure& Cure::operator=(const Cure& Cure)
{
	if (this != &Cure)
		this->type = Cure.type;
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "Cure:\"* heals \"" << target.getName() << "'s wounds *" << std::endl;
}