#include "ft_c.h"

typedef int	(*t_ptr)(int, int);

int		ft_atoi(char	*str);
void	*ft_set_table(char	*str, char	*c);

int	main(int	argc, char	**argv)
{
	int		num1;
	int		num2;
	int		i;
	t_ptr	c[5];
	char	f[5];

	if (argc != 4)
		return (0);
	if (argv[2] != '+' && argv[2] != '-' && argv[2] != '/'
		&& argv[2] != '*' && argv[2] != '%')
	{
		write(1, "0", 1);
		return (0);
	}
	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[3]);
	ft_set_table(f[0], c[0]);
	i = 0;
	while (f[i])
	{
		if (f[i] == argv[2][0])
			ft_putnbr(c[i](num1, num2));
		i++;
	}
	return (0);
}

int	ft_atoi(char	*str)
{
	int	i;
	int	g;
	int	num;

	i = 0;
	g = 1;
	num = 0;
	while (str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			g = -g;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	num = num * g;
	return (num);
}

void	*ft_set_table(char	*str, char	*c)
{
	str[0] = '+';
	str[1] = '-';
	str[2] = '/';
	str[3] = '*';
	str[4] = '%';
	c[0] = ft_add_num(int, int);
	c[1] = ft_sub_num(int, int);
	c[2] = ft_div_num(int, int);
	c[3] = ft_mul_num(int, int);
	c[4] = ft_mod_num(int, int);
}
