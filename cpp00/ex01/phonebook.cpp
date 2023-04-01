#include "phonebook.hpp"

void	PhoneBook::add_contact()
{
	static int	idx;
	Contact	contact;
	std::string	first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string	darkest_secret;

	std::cout << "insert first name: ";
	std::getline(std::cin, first_name);
	std::cout << "insert last name: ";
	std::getline(std::cin, last_name);
	std::cout << "insert nick name: ";
	std::getline(std::cin, nick_name);
	std::cout << "insert phone number: ";
	std::getline(std::cin, phone_number);
	std::cout << "insert darkest secret: ";
	std::getline(std::cin, darkest_secret);
	if (first_name.size() > 0 && last_name.size() > 0 && nick_name.size() > 0 && phone_number.size() > 0 && darkest_secret.size() > 0)
	{
		contact = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);
		this->contact[idx % 8] = contact;
		this->contact_num = idx;
		idx++;
	}
}

void	PhoneBook::search_contact(int idx)
{
	int	index;

	index = idx - 1;
	std::string	str[3];
	if (index < 0 || index > 7)
	{
		std::cout << "wrong index" << std::endl;
		return ;
	}
	if (this->contact[index].get_first_name().size() < 1)
	{
		std::cout << "empty" << std::endl;
		return ;
	}
	else
	{
		str[0] = this->contact[index].get_first_name();
		if (str[0].size() > 10)
			str[0].replace(9, str[0].size() - 9, ".");
		str[1] = this->contact[index].get_last_name();
		if (str[1].size() > 10)
			str[0].replace(9, str[0].size() - 9, ".");
		str[2] = this->contact[index].get_nick_name();
		if (str[2].size() > 10)
			str[0].replace(9, str[0].size() - 9, ".");
		std::cout << "|" << std::setw(10) << idx << "|" << std::setw(10) << str[0] << "|" \
			<< std::setw(10) << str[1] << "|"<< std::setw(10) << str[2] << "|" << std::endl;
	}
}

void	PhoneBook::search_contact()
{
	int			idx;
	std::string	select_idx;
	std::string	str[3];

	str[0] = this->contact[0].get_first_name();
	if (str[0].size() < 1)
	{
		std::cout << "empty" << std::endl;
		return ;
	}
	idx = 0;
	while (idx < 8 && this->contact[idx].get_first_name().size() > 0)
	{
		str[0] = this->contact[idx].get_first_name();
		if (str[0].size() > 10)
			str[0].replace(9, str[0].size() - 9, ".");
		str[1] = this->contact[idx].get_last_name();
		if (str[1].size() > 10)
			str[0].replace(9, str[0].size() - 9, ".");
		str[2] = this->contact[idx].get_nick_name();
		if (str[2].size() > 10)
			str[0].replace(9, str[0].size() - 9, ".");
		std::cout << "|" << std::setw(10) << idx + 1 << "|" << std::setw(10) << str[0] << "|" \
			<< std::setw(10) << str[1] << "|" << std::setw(10) << str[2] << "|" << std::endl;
		idx++;
	}
	std::cout << "insert idx if insert 0 exit" << std::endl;
	std::getline(std::cin, select_idx);
	if (select_idx.size() > 1 || (select_idx[0] > '8' || select_idx[0] < '0'))
		return ;
	search_contact(std::stoi(select_idx));
}

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
	std::cout << "execute phonebook destructor" << std::endl;
}
