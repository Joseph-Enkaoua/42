#include <iostream>
#include <cctype>

int	main(int argc, char **argv){
	int	j;
	int	i;

	(void)argv;
	if (argc > 1)
	{
		j = 0;
		while (argv[++j])
		{
			i = -1;
			while (argv[j][++i])
			{
				argv[j][i] = toupper(argv[j][i]);
				if (argv[j][i] != '"')
					std::cout << argv[j][i];
			}	
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}
