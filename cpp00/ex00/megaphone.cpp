#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int		idx;
	int		i;
	char	c;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		idx = 0;
		while (argv[++idx])
		{
			i = -1;
			while (argv[idx][++i])
			{
				if (argv[idx][i] >= 'a' && argv[idx][i] <= 'z')
					c = argv[idx][i] - 32;
				else
					c = argv[idx][i];
				std::cout << c;
			}
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
}