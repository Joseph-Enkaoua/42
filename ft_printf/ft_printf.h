/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henkaoua <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:37:58 by henkaoua          #+#    #+#             */
/*   Updated: 2021/11/12 11:59:40 by henkaoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *type, ...);
int	print_int(int nb);
int	print_unsigned_int(unsigned int u);
int	print_pointer(unsigned long int p);
int	print_hex_l(unsigned int d);
int	print_hex_u(unsigned int x);
#endif
