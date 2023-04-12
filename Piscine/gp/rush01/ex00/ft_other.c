/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmartin <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:15:22 by olmartin          #+#    #+#             */
/*   Updated: 2021/08/15 15:43:40 by olmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str);
int		ft_str_is_numeric(char *str);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	ft_is_numeric(char *str)
{
	int	flag;
	int	i;
	int	as;

	i = 0;
	flag = 1;
	while (str[i] != 0)
	{
		as = (int) str[i];
		if (!(as >= 48 && as <= 57))
			flag = 0;
		i++;
	}
	return (flag);
}
