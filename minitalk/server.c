/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:34:06 by henkaoua          #+#    #+#             */
/*   Updated: 2022/01/14 16:25:09 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ptcr(char *d, int i)
{
	int	p;

	while (!(i < 0))
	{
		p = d[i];
		write(1, &p, 1);
		i--;
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int nb)
{
	int		i;
	char	d[12];

	i = 0;
	while (nb > 9)
	{
		d[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	d[i] = nb + 48;
	ptcr(d, i);
}

void	sig_handler(int signum)
{
	static char	c = 0;
	static int	i = 8;
	static int	num = 256;

	num = num / 2;
	if (signum == 31)
		c = c + num;
	i--;
	if (i == 0)
	{
		i = 8;
		write(1, &c, 1);
		num = 256;
		c = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	ft_putnbr(getpid());
	while (1)
		pause();
	return (0);
}
