#include <iostream>
#include <cstring>

int	main(int ac, char **av)
{
	int i, j;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	i = 1;
	while (i < ac)
	{
		j = -1;
		while (av[i][++j])
			std::cout << (char)toupper(av[i][j]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}
