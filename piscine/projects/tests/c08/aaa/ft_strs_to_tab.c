#include "ft_stock_str.h"
#include <stdlib.h>
void	ft_show_tab(struct s_stock_str	*par);

int	ft_setarr(char	*av, t_stock_str	*rapset)
{
	int		i;
	int		x;
	char	*str;

	i = 0;
	while (av[i])
		i++;
	str = (char	*)malloc((i + 1) * (sizeof(char)));
	if (str == NULL)
		return (0);
	(*rapset).size = i;
	(*rapset).str = av;
	(*rapset).copy = str;
	x = 0;
	while (x < i)
	{
		str[x] = av[x];
		x++;
	}
	str[x] = 0;
	return (1);
}

struct s_stock_str	*ft_strs_to_tab(int	ac, char	**av)
{
	int			i;
	t_stock_str	*rap;

	rap = (t_stock_str *)malloc((ac + 1) * (sizeof(*rap)));
	if (rap == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (!ft_setarr(av[i], &rap[i]))
			return (NULL);
		i++;
	}
	(rap[i]).str = 0;
	return (rap);
}

int	main(int	argc, char	**argv)
{
	ft_show_tab(ft_strs_to_tab(argc, argv));
	return (0);
}
