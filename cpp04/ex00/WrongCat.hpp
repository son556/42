#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "./WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& wrongcat);
		virtual ~WrongCat();
		WrongCat& operator=(const WrongCat& wrongcat);
		void makeSound() const;
};
#endif