#include "./IMateriaSource.hpp"
#include "./Ice.hpp"
#include "./Cure.hpp"
#include "./Character.hpp"
#include "./MateriaSource.hpp"
#include "./ICharacter.hpp"


void    iMaterSourceTest(IMateriaSource& skillBook)
{
	std::cout << "[IMateriaSource test]" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cout << "Filling skill book [ice][ice][ice][cure]" << std::endl;
	Ice ice;
	Cure cure;
	skillBook.learnMateria(&ice);
	skillBook.learnMateria(&ice);
	skillBook.learnMateria(&cure);
	skillBook.learnMateria(&cure);
	std::cout << "================================================================" << std::endl;
}

void    equipTest(ICharacter& target, IMateriaSource& skillBook)
{
	std::cout << "\n[Equip test]" << std::endl;
	std::cout << "================================================================" << std::endl;
	AMateria* tmp;
	tmp = skillBook.createMateria("ice");
	target.equip(tmp);
	tmp = skillBook.createMateria("cure");
	target.equip(tmp);

	std::cout << "\nFilling character's inventory with created other Materia" << std::endl;
	tmp = skillBook.createMateria("cure");
	target.equip(tmp);
	tmp = skillBook.createMateria("cure");
	target.equip(tmp);
	std::cout << "\nCharacter's inventory [ice][cure][cure][cure]" << std::endl;

	std::cout << "\n[Character's inventory slot is full]" << std::endl;
	tmp = skillBook.createMateria("cure");
	target.equip(tmp);
	delete tmp;
	std::cout << "================================================================" << std::endl;
}

void    useTest(ICharacter& target)
{
	std::cout << "\n[Use test]" << std::endl;
	std::cout << "================================================================" << std::endl;
	std::cout << "\nTesting a character's use of a skill (material) in order" << std::endl;
	target.use(0, target);
	target.use(1, target);
	target.use(2, target);
	target.use(3, target);
	std::cout << "================================================================" << std::endl;
}

void    unequipTest(ICharacter& target)
{
	std::cout << "\n[Unequip test]" << std::endl;
	std::cout << "================================================================" << std::endl;
	target.unequip(0);
	target.use(0, target);


	target.unequip(3);
	target.use(3, target);
	std::cout << "================================================================" << std::endl;
}

void    rangeTest(ICharacter& target)
{
	std::cout << "\n[range test]" << std::endl;
	std::cout << "================================================================" << std::endl;
	target.unequip(4);
	target.unequip(-2147483648);
	target.use(4, target);
	target.use(-2147483648, target);
	std::cout << "================================================================" << std::endl;
}

void    interactiveTest(ICharacter& target, IMateriaSource& skillBook)
{
	iMaterSourceTest(skillBook);
	equipTest(target, skillBook);
	useTest(target);
	unequipTest(target);
	rangeTest(target);
}

// void leak(void)
// {
// 	system("leaks $PPID");
// }

int main()
{	
	// atexit(leak);

	IMateriaSource* skillBook = new MateriaSource();
	ICharacter* me = new Character("me");
	ICharacter* monster = new Character("monster");
	Character* user1 = new Character("user1");
	Character* user2 = new Character("user2");
	interactiveTest(*me, *skillBook);

	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->equip(skillBook->createMateria("ice"));
	me->equip(skillBook->createMateria("cure"));
	me->equip(skillBook->createMateria("ice"));
	me->equip(skillBook->createMateria("cure"));
	user1->equip(skillBook->createMateria("ice"));
	user1->equip(skillBook->createMateria("cure"));
	*user2 = *user1;
	std::cout << user2->getName() << std::endl;
	user2->use(0, *me);
	me->use(0, *monster);
	me->use(1, *monster);
	me->use(2, *monster);
	me->use(3, *monster);
	delete monster;
	delete skillBook;
	delete me;
	delete user1;
	delete user2;
	return 0;
}