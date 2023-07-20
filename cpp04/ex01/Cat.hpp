#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal, public Brain
{
	private:
		Brain *br;
	public:
		Cat();
		Cat(const std::string &type);
		Cat(const Cat& cat);
		Cat(const Brain& brain);
		Cat& operator=(const Cat& cat);
		virtual ~Cat();
		virtual void makeSound() const;
};
#endif