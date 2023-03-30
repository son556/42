#include "contact.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, \
	std::string phone_number, std::string darkest_secret)
{
	this->firt_name = first_name;
	this->last_name = last_name;
	this->nick_name = nick_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

Contact::Contact()
{
	Contact("", "", "", "", "");
}

std::string Contact::get_first_name()
{
	return (this->firt_name);
}

std::string Contact::get_last_name()
{
	return (this->last_name);
}

std::string Contact::get_nick_name()
{
	return (this->nick_name);
}

std::string Contact::get_phone_number()
{
	return (this->phone_number);
}
