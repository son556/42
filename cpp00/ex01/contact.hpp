#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
private:
	std::string	firt_name;
	std::string last_name;
	std::string nick_name;
	std::string	phone_number;
	std::string	darkest_secret;
public:
	Contact(std::string first_name, std::string last_name, std::string nick_name, \
	std::string phone_number, std::string darkest_secret);
	Contact();
	std::string	get_first_name();
	std::string	get_last_name();
	std::string get_nick_name();
	std::string	get_phone_number();
};

#endif