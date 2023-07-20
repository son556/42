#include "./MateriaSource.hpp"
#include "./AMateria.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		search[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& ms)
{
	*this = ms;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ms)
{
	if (this != &ms)
	{
		for (int i = 0; i < 4; i++)
		{
			delete search[i];
			search[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (ms.search[i] == NULL)
				break ;
			search[i] = ms.search[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{	
		delete search[i];
		search[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria* ms)
{
	if (ms == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (search[i] == NULL)
		{
			search[i] = ms->clone();
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (search[i] != NULL && search[i]->getType() == type)
			return (search[i]->clone());
	}
	return (0);
}
