#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char	*str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

void	ft_itos(int	num)
{
	if (num > 9)
		ft_itos(num / 10);
	ft_putchar(num % 10 + 48);
}

void	ft_show_tab(struct s_stock_str	*par)
{
	int	i;

	i = -1;
	while (par[++i].str)
	{
		ft_putstr((par[i]).str);
		ft_itos((par[i]).size);
		write(1, "\n", 1);
		ft_putstr((par[i]).copy);
	}
}
