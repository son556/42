#include "./Dog.hpp"
#include "./Cat.hpp"

int main()
{
	const Animal* j = new Dog();
 	const Animal* i = new Cat();
 	delete j;
 	delete i;
  
 	Animal	*a[4];

	for(int i=0; i<4; i++)
	{
		if (i < 2)
			a[i] = new Cat();
		else
			a[i] = new Dog();
	}
	for(int i=0; i<4; i++)
		a[i]->makeSound();
	
	for(int i=0; i<4; i++)
		delete a[i];
	Brain brain;
	Cat cat(brain);
	Dog dog(brain);

	brain.setIdea("hello world", 2);
	cat.setIdea("i like fish", 3);
	dog.setIdea("dog dog", 4);

	std::cout << brain.getIdea(2) << std::endl;
	std::cout << cat.getIdea(3) << std::endl;
	std::cout << dog.getIdea(4) << std::endl;

	return (0);
}