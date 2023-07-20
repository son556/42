#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "./IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *search[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& ms);
		MateriaSource& operator=(const MateriaSource& ms);
		~MateriaSource();
		virtual void learnMateria(AMateria*);
    	virtual AMateria* createMateria(std::string const & type);
};
#endif
