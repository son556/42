#include "./Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "nothing";
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& brain)
{
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = brain.ideas[i];
	}
	return (*this);
}

void Brain::setIdea(const std::string &idea, const int &idx)
{
	ideas[idx % 100] = idea;
}

std::string Brain::getIdea(const int& idx) const
{
	return (ideas[idx % 100]);
}
