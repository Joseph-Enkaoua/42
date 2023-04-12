/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:57:11 by henkaoua          #+#    #+#             */
/*   Updated: 2022/01/14 13:24:35 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	num;
	int	i;
	int	g;

	num = 0;
	i = 0;
	g = 1;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == '-')
			g = -1;
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

static void	send_signal(char *str, int pid)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_signal(argv[2], pid);
	}
	return (0);
}
