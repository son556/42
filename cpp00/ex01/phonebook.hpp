#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"
# include <iomanip>
# include <string>
# include <iostream>

class PhoneBook {
	private:
		Contact	contact[8];
		int	contact_num;
	public:
		PhoneBook();
		void	add_contact();
		void	search_contact(int index);
		void	search_contact();
		~PhoneBook();
};
#endif
