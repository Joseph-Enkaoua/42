#include <unistd.h>

int	main(int	argc, char	**argv)
{
	int	i;
	int	x;

	i = 0;
	x = 1;
	if (argc > 1)
	{
		while (x < argc)
		{
			while (argv[x][i])
			{
				write(1, &argv[x][i], 1);
				i++;
			}
			write(1, "\n", 1);
			x++;
			i = 0;
		}
	}
	return (0);
}
