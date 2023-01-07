/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:53:21 by henkaoua          #+#    #+#             */
/*   Updated: 2021/11/11 10:53:29 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ptcr(char *d, int i)
{
	int	p;

	while (!(i < 0))
	{
		p = d[i];
		write(1, &p, 1);
		i--;
	}
}

static void	negative(int *nb, char *g)
{
	if (*nb < 0)
	{
		if (*nb == -2147483648)
		{
			(*nb)++;
			*g = 1;
		}
		*nb = *nb * -1;
		(*g)++;
	}
}

int	print_int(int nb)
{
	char	g;
	char	d[12];
	int		i;
	int		ret;

	i = 0;
	g = 0;
	negative(&nb, &g);
	while (nb > 9)
	{
		d[i] = nb % 10 + 48;
		if (g == 2)
			d[0] = 56;
		nb = nb / 10;
		i++;
	}
	d[i] = nb + 48;
	if (g > 0)
		d[++i] = '-';
	ret = i + 1;
	ptcr(d, i);
	return (ret);
}

int	print_unsigned_int(unsigned int u)
{
	char	s[12];
	int		i;
	int		ret;

	i = 0;
	while (u > 9)
	{
		s[i] = u % 10 + 48;
		u = u / 10;
		i++;
	}
	s[i] = u + 48;
	ret = i + 1;
	ptcr(s, i);
	return (ret);
}
