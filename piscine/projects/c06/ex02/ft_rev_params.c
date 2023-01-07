#include <unistd.h>

int	main(int	argc, char	**argv)
{
	int	x;
	int	i;

	x = argc - 1;
	i = 0;
	if (argc > 1)
	{
		while (x > 0)
		{
			while (argv[x][i])
			{
				write(1, &argv[x][i], 1);
				i++;
			}
			write(1, "\n", 1);
			x--;
			i = 0;
		}
	}
	return (0);
}
