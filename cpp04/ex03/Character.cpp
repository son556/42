#include "./Character.hpp"
#include "./AMateria.hpp"

AMateria** Character::floor = NULL;
int Character::cnt = 0;

Character::Character() : name("noname")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const std::string c_name) : name(c_name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& character)
{
	*this = character;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
}

Character& Character::operator=(const Character& character)
{
	if (this != &character)
	{
		if (inventory[0] != NULL)
		{
			for (int i = 0; i < 4; i++)
				delete inventory[i];
		}
		name = character.name;
		for (int i = 0; i < 4; i++)
		{
			if (character.inventory[i] == NULL)
				inventory[i] = NULL;
			else
			{
				inventory[i] = character.inventory[i]->clone();
			}
		}
	}
	return (*this);
}

std::string const& Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	AMateria **tmp_floor;

	if (idx > 3 || idx < 0 || inventory[idx] == NULL)
		return ;
	else
	{
		tmp_floor = new AMateria*[cnt + 1];
		for (int i = 0; i < cnt; i++)
			tmp_floor[i] = floor[i];
		tmp_floor[cnt] = inventory[idx];
		delete floor;
		floor = tmp_floor;
		inventory[idx] = NULL;
		cnt++;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (inventory[idx] == NULL)
		return ;
	inventory[idx]->use(target);
}

void Character::getFloor(int idx)
{
	if (idx < 0 || idx >= cnt || floor[idx] == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = floor[idx];
			floor[idx] = NULL;
			for (int i = idx; i < cnt; i++)
			{
				if (floor[i + 1] != NULL)
					floor[i] = floor[i + 1];
			}
			cnt--;
			break ;
		}
	}
}