#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:
		static bool flag;
		static double convert(std::string str);
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &ref);
		ScalarConverter& operator=(const ScalarConverter &ref);
		~ScalarConverter();
		static void convertChar(std::string str);
		static void convertInt(std::string str);
		static void convertFloat(std::string str);
		static void convertDouble(std::string str);
};
#endif