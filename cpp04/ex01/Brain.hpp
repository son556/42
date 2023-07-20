#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& brain);
		~Brain();
		Brain& operator=(const Brain& brain);
		std::string getIdea(const int &idx) const;
		void setIdea(const std::string& idea, const int &idx);
};
#endif