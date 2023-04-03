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
	std::string	new_s;
	size_t	idx;

	if (!in.is_open())
	{
		std::cout << "no file" << std::endl;
		return (1);
	}
	while (!in.eof())
	{
		std::getline(in, s);
		while ((idx = s.find(argv[2])) != std::string::npos)
		{
			new_s = argv[2];
			s.erase(idx, new_s.size());
			s.insert(idx, argv[3]);
		}
		if (!in.eof())
			newfile << s << std::endl;
		else
			newfile << s;
	}
	return (0);
}