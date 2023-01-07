#include <stdlib.h>

void	ft_putstr(char *str);
int		ft_test_para(int *para, char *str);
int		ft_test_para_sum(int *para);

int	main(int argc, char **argv)
{
	char	*ptr;
	int		i;
	int		*ptr_para;
	int		flag;

	i = 1;
	flag = 0;
	ptr_para = (int *)malloc(sizeof(*ptr_para) * 16);
	ptr = (char *)malloc(sizeof(*ptr) * 6);
	ptr = "Error\n";
	if (argc == 2)
	{
		flag = ft_test_para(ptr_para, argv[1]);
	}
	else
		flag = 1;
	if (flag == 1)
		ft_putstr(ptr);
	free(ptr_para);
	return (0);
}

/*Test des parametres */
int	ft_test_para(int *tab_para, char *str)
{
	int	a;
	int	i;
	int	as;
	int	flag;

	a = 0;
	flag = 0;
	i = 0;
	while (str[a] != 0)
	{
		as = (int) str[a];
		if (as > 48 && as < 53)
		{
			tab_para[i] = str[a] - '0';
			i++;
		}
		else if (as != 32)
			return (1);
		a++;
	}
	if (i != 16)
		flag = 1;
	if (ft_test_para_sum(tab_para) != 0)
		flag = 1;
	return (flag);
}

int	ft_test_para_sum(int *tab_par)
{
	int	i;
	int	sum_col;

	i = 0;
	while (i < 8)
	{
		sum_col = tab_par[i] + tab_par[i + 4];
		if ((sum_col > 5) || ((tab_par[i] + tab_par[i + 4]) < 3))
		{
			return (1);
		}	
		i++;
	}
	return (0);
}
