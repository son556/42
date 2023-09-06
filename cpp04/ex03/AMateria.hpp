#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
// #include "./ICharacter.hpp"
class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria(const AMateria& am);
		AMateria& operator=(const AMateria& am);
		virtual ~AMateria();
		const std::string& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};
#endif