/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:38:17 by henkaoua          #+#    #+#             */
/*   Updated: 2021/11/12 11:39:47 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long int p)
{
	char	str[16];
	int		i;
	int		ret;

	i = 0;
	if (p == 0)
		str[i++] = '0';
	while (p > 0)
	{
		if ((p % 16) >= 0 && (p % 16) < 10)
			str[i] = '0' + (p % 16);
		else
			str[i] = 'a' + ((p % 16) - 10);
		i++;
		p = p / 16;
	}
	str[i++] = 'x';
	str[i] = '0';
	ret = i + 1;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	return (ret);
}

int	print_hex_l(unsigned int d)
{
	char	str[16];
	int		i;
	int		ret;

	i = 0;
	if (d == 0)
		str[i++] = '0';
	while (d > 0)
	{
		if ((d % 16) >= 0 && (d % 16) < 10)
			str[i] = '0' + (d % 16);
		else
			str[i] = 'a' + ((d % 16) - 10);
		i++;
		d = d / 16;
	}
	ret = i;
	i--;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	return (ret);
}

int	print_hex_u(unsigned int x)
{
	char	str[16];
	int		i;
	int		ret;

	i = 0;
	if (x == 0)
		str[i++] = '0';
	while (x > 0)
	{
		if ((x % 16) < 10)
			str[i] = (x % 16) + 48;
		else
			str[i] = (x % 16) + 55;
		i++;
		x = x / 16;
	}
	ret = i;
	i--;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	return (ret);
}
