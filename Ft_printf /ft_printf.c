/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:49:14 by henkaoua          #+#    #+#             */
/*   Updated: 2021/12/07 15:25:15 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_str(char *s)
{
	int	i;

	i = -1;
	if (s == NULL)
		s = "(null)\0";
	while (s[++i])
		write(1, &s[i], 1);
	return (i);
}

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

void	send_arg(const char *type, va_list args, int *i, int *cnt)
{
	if (type[++(*i)] == 'c')
		*cnt += print_char(va_arg(args, int));
	if (type[*i] == 's')
		*cnt += print_str(va_arg(args, char *));
	if (type[*i] == 'p')
		*cnt += print_pointer(va_arg(args, unsigned long int));
	if (type[*i] == 'd')
		*cnt += print_int(va_arg(args, int));
	if (type[*i] == 'i')
		*cnt += print_int(va_arg(args, int));
	if (type[*i] == 'u')
		*cnt += print_unsigned_int(va_arg(args, unsigned int));
	if (type[*i] == 'x')
		*cnt += print_hex_l(va_arg(args, unsigned int));
	if (type[*i] == 'X')
		*cnt += print_hex_u(va_arg(args, unsigned int));
	if (type[*i] == '%')
		*cnt += print_char('%');
}

int	ft_printf(const char *type, ...)
{
	int		i;
	int		cnt;
	va_list	args;

	cnt = 0;
	va_start(args, type);
	i = -1;
	while (type[++i])
	{
		if (type[i] == '%')
			send_arg(type, args, &i, &cnt);
		else
			cnt += print_char(type[i]);
	}
	va_end(args);
	return (cnt);
}

/*int	main()
{
	int	p;

	p = 10;
	printf("%d\n", ft_printf("%X\n", p));
	printf("%d\n", printf("%X\n", p));
	return (0);
}*/
