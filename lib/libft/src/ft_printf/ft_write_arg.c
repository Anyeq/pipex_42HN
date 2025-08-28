/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:54:24 by asando            #+#    #+#             */
/*   Updated: 2025/04/24 12:11:47 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	write_arg(unsigned char c, va_list args, t_prse *prse, int *i)
{
	int			nchar;
	const char	*xsmall;
	const char	*xbig;

	xsmall = "0123456789abcdef";
	xbig = "0123456789ABCDEF";
	nchar = 0;
	if (c == 'c')
		nchar += ft_putchar(va_arg(args, unsigned int), prse);
	else if (c == '%')
		nchar += ft_putchar('%', prse);
	else if (c == 's')
		nchar += ft_putstr(va_arg(args, char *), prse);
	else if (c == 'p')
		nchar += ft_putptr(va_arg(args, void *), prse);
	else if (c == 'd' || c == 'i')
		nchar += ft_putint(va_arg(args, int), prse);
	else if (c == 'u')
		nchar += ft_putunint(va_arg(args, unsigned int), prse);
	else if (c == 'x')
		nchar += ft_putnum_base(va_arg(args, unsigned int), 16, xsmall, prse);
	else if (c == 'X')
		nchar += ft_putnum_base(va_arg(args, unsigned int), 16, xbig, prse);
	*i += 1;
	return (nchar);
}
