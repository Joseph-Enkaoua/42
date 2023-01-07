#include <unistd.h>

void	ft_printstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_switch(char	**av, int	i)
{
	char	*temp;

	temp = av[i];
	av[i] = av[i + 1];
	av[i + 1] = temp;
}

int	ft_sizecheck(char	*av, char	*av1)
{
	int	d;
	int	x;

	d = 0;
	x = 0;
	while (*av == *av1)
	{
		if (*av == '\0' && *av1 == '\0')
			return (d);
		av++;
		av1++;
	}
	d = *av - *av1;
	return (d);
}

int	main(int	ac, char	**av)
{
	int	i;
	int	x;

	i = 1;
	while (i < ac - 1)
	{
		x = ft_sizecheck(av[i], av[i + 1]);
		if (x > 0)
		{
			ft_switch(av, i);
			i = 0;
		}
		i++;
	}
	i = 1;
	while (i < ac)
	{
		ft_printstr(av[i]);
		i++;
	}
	return (0);
}
