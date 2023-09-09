#include "ScalarConverter.hpp"

bool ScalarConverter::flag = false;

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& ref)
{
	*this = ref;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref)
{
	(void) ref;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

double ScalarConverter::convert(std::string str)
{
	double num = 0, num2 = 1, sign = 0;
	int sw = 0, dot = 0;
	for (int i = 0; i < int(str.length()); i++)
	{
		if (sw == 0 && str[i] == ' ') continue;
		if (sw == 0 && (str[i] > '9' || str[i] < '0') && str[i] != '+' && str[i] != '-' && str.length() > 1)
		{
			flag = false;
			return num;
		}
		sw = 1;
		if (sw && str[i] == ' ')
		{
			flag = false;
			return num;
		}
		if (str[i] == '+' || str[i] == '-')
			sign++;
		if (str[i] == '.')
			dot++;
	}
	if (int(str.length()) > 1 && str[str.length() - 1] != 'f' && (str[str.length() - 1] > '9' || str[str.length() - 1] < '0'))
	{
		flag = false;
		return num;
	}
	if (str[str.length() - 1] == 'f' && (str[str.length() - 2] > '9' || str[str.length() - 2] < '0'))
	{
		flag = false;
		return num;
	}
	if (sign > 1 || dot > 1)
	{
		flag = false;
		return num;
	}
	sign = 1;
	if (str.length() == 1 && (str[0] > '9' || str[0] < '0'))
	{
		num = static_cast<double>(str[0]);
		flag = true;
		return num;
	}
	sw = 0;
	for (int i = 0; i < int(str.length()); i++)
	{
		if (str[i] == ' ') continue;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '+')
				sign = 1;
			else
				sign = -1;
			continue;
		}
		if (sw == 0 && str[i] <= '9' && str[i] >= '0')
			num = num * 10 + (str[i] - '0') * sign;
		else if (str[i] == '.')
			sw = 1;
		else if (sw && str[i] >= '0' && str[i] <= '9')
		{
			num2 *= 0.1;
			num += num2 * (str[i] - '0') * sign;
		}
		else if (str[i] > '9' || str[i] < '0')
		{
			if (i != int(str.length()) - 1)
			{
				flag = false;
				return num;
			}
			if (str[i] != 'f')
			{
				flag = false;
				return num;
			}
		}
	}
	flag = true;
	return num;
}

void ScalarConverter::convertChar(std::string str)
{
	double n;

	n = convert(str);
	if (flag == false)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (n < 32 || n > 126)
	{
		std::cout << "char: Non displayable" << std::endl;
		return;
	}
	std::cout<< "char: " << static_cast<char>(int(n)) << std::endl;
	return ;
}

void ScalarConverter::convertDouble(std::string str)
{
	double n;
	std::string sign = "", sample;
	int idx = 0;

	n = convert(str);
	if (flag == false)
	{
		sample = str;
		for (int i = 0; i < int(str.length()); i++)
			if (str[i] == ' ') idx = i;
		str = str.substr(idx);
		if (str[0] == '+' || str[0] == '-')
		{
			if (str[0] == '-')
				sign = "-";
			str = str.substr(1);
		}
		if (str == "nan" || str == "nanf" || str == "inf" || str == "inff")
		{
			if (str.length() != 4)
				std::cout << "double: " << sign + str << std::endl;
			else
				std::cout << "double: " << sign + str.substr(0, 3) << std::endl;
			return ;
		}
		std::cout << "< " << sample << " > is not correct type." << std::endl;
		return ;
	}
	if (n == 0.0)
	{
		std::cout << "double: 0.0" << std::endl;
		return ;
	}
	std::cout << "double: " << n << std::endl;
	return ;
}

void ScalarConverter::convertFloat(std::string str)
{
	double n;
	std::string sign = "", sample;
	int idx = 0;

	n = convert(str);
	if (flag == false)
	{
		sample = str;
		for (int i = 0; i < int(str.length()); i++)
			if (str[i] == ' ') idx = i;
		str = str.substr(idx);
		if (str[0] == '+' || str[0] == '-')
		{
			if (str[0] == '-')
				sign = "-";
			str = str.substr(1);
		}
		if (str == "nan" || str == "nanf" || str == "inf" || str == "inff")
		{
			if (str.length() != 4)
				std::cout << "float: " << sign + str + "f" << std::endl;
			else
				std::cout << "float: " << sign + str << std::endl;
			return ;
		}
		std::cout << "< " << sample << " > is not correct type." << std::endl;
		return ;
	}
	if (n == 0.0)
	{
		std::cout << "float: 0.0f" << std::endl;
		return ;
	}
	std::cout << "float: " << static_cast<float>(n) << 'f' << std::endl;
	return ;
}

void ScalarConverter::convertInt(std::string str)
{
	double n;
	std::string sign = "", sample;
	int idx = 0;

	n = convert(str);
	if (flag == false)
	{
		sample = str;
		for (int i = 0; i < int(str.length()); i++)
			if (str[i] == ' ') idx = i;
		str = str.substr(idx);
		if (str[0] == '+' || str[0] == '-')
		{
			if (str[0] == '-')
				sign = "-";
			str = str.substr(1);
		}
		if (str == "nan" || str == "nanf" || str == "inf" || str == "inff")
		{
			std::cout << "int: impossible" << std::endl;
			return ;
		}
		std::cout << "< " << sample << " > is not correct type." << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	return ;
}