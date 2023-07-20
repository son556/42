#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &wronganimal);
		virtual ~WrongAnimal();
		void makeSound() const;
		std::string getType() const;
		WrongAnimal& operator=(const WrongAnimal &wronganimal);
};
#endif