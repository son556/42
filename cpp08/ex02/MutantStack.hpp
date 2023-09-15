#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack& ref) { *this = ref; }
		MutantStack& operator=(const MutantStack& ref) { *this = ref; return *this; }
		~MutantStack() {}
		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		
		typedef typename MutantStack<T>::stack::container_type::reverse_iterator r_iterator;
		r_iterator rbegin() { return this->c.rbegin(); }
		r_iterator rend() { return this->c.rend(); }

		typedef typename MutantStack<T>::stack::container_type::const_iterator c_iterator;
		c_iterator cbegin() const { return this->c.cbegin(); }
		c_iterator cend() const { return this->c.cend(); }

		typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator cr_iterator;
		cr_iterator crbegin() { return this->c.crbegin(); }
		cr_iterator crend() { return this->c.crend(); }
};

#endif