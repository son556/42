#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (0);

	std::ifstream in(argv[1]);
	std::string	file_name = argv[1];
	std::ofstream newfile(file_name + ".replace");
	std::string	s;

	if (!in.is_open())
	{
		std::cout << "no file" << std::endl;
		return (1);
	}
	while (!in.eof())
	{
		std::getline(in, s);
		if (s.find(argv[2]) != std::string::npos)
		{
			s = argv[3];
			std::cout << "flag" << std::endl;
			std::cout << s << std::endl;
		}
		else
			std::cout << s << std::endl;
		if (!in.eof())
			newfile << s << std::endl;
		else
			newfile << s;
	}
	return (0);
}