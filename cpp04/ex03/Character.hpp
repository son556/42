#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "./ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[4];
		static AMateria **floor;
		static int cnt;
	public:
		Character();
		Character(const std::string c_name);
		Character(const Character& character);
		~Character();
		Character& operator=(const Character& character);
		virtual std::string const& getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		virtual void getFloor(int idx);
};

#endif