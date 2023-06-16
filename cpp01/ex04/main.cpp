#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "argc err: " << argc << std::endl;
		return (0);
	}

	std::ifstream in(argv[1]);
	std::string	file_name = argv[1];
	file_name += ".replace";
	std::ofstream newfile(file_name.c_str());
	std::string	s;
	std::string	new_s;
	size_t	idx;

	if (!in.is_open() || !newfile.is_open())
	{
		std::cout << "no file" << std::endl;
		return (1);
	}
	new_s = argv[2];
	while (!in.eof())
	{
		std::getline(in, s, '\0');
		while ((idx = s.find(argv[2])) != std::string::npos)
		{
			s.erase(idx, new_s.size());
			s.insert(idx, argv[3]);
		}
		newfile << s;
	}
	return (0);
}