#ifndef CURE_HPP
#define CURE_HPP

#include "./AMateria.hpp"

#include "./ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& cure);
		virtual ~Cure();
		Cure& operator=(const Cure& cure);
		void use(ICharacter& target);
		AMateria* clone() const;
};
#endif