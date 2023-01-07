#include "ft_c.h"

void	ptcr(char	*d, int	i)
{
	int	p;

	while (!(i < 0))
	{
		p = d[i];
		write(1, &p, 1);
		i--;
	}
}

void	negative(int	*nb, char	*g)
{
	if (*nb < 0)
	{
		*nb = *nb * -1;
		(*g)++;
	}
}

void	ft_putnbr(int	nb)
{
	char	g;
	int		i;
	char	d[12];

	i = 0;
	g = 0;
	negative(&nb, &g);
	while (nb > 9)
	{
		d[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	d[i] = nb + 48;
	if (g > 0)
		d[++i] = '-';
	ptcr(d, i);
}
