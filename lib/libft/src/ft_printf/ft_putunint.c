/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2025/07/18 10:50:56 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	putunint_out(unsigned int n, t_prse *prse)
{
	char	c;

	if (n == 0)
	{
		if (write(1, "0", 1) < 1)
		{
			prse->write_err = 1;
			return ;
		}
		return ;
	}
	if (n / 10 > 0 && prse->write_err != 1)
		putunint_out(n / 10, prse);
	c = (n % 10) + '0';
	if (prse->write_err != 1)
	{
		if (write(1, &c, 1) < 1)
		{
			prse->write_err = 1;
			return ;
		}
	}
	return ;
}

static int	print_arg(int n, int f_dot, int precision, t_prse *prse)
{
	char	char_print;

	char_print = ' ';
	if (prse->width == 0)
		char_print = '\0';
	if (f_dot == 1 && precision == 0 && n == 0)
	{
		if (ft_printchar(char_print, prse) == 0)
			return (-1);
		return (1);
	}
	if (prse->write_err != 1)
		putunint_out(n, prse);
	if (prse->write_err == 1)
		return (-1);
	return (1);
}

int	ft_putunint(unsigned int n, t_prse *prse)
{
	int	nstr;
	int	nd;

	nstr = count_digit_uint(n);
	nd = nstr;
	if (prse->precision == 0 && prse->flag_dot == 1 && n == 0)
		nd = 0;
	if (prse->flag_dot == 1)
		prse->flag_zero = 0;
	if (prse->flag_minus == 0)
	{
		nd += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
		nd += write_precision(prse->precision, nstr);
		if (print_arg(n, prse->flag_dot, prse->precision, prse) != 1)
			return (-1);
	}
	else if (prse->flag_minus == 1)
	{
		nd += write_precision(prse->precision, nstr);
		if (print_arg(n, prse->flag_dot, prse->precision, prse) != 1)
			return (-1);
		nd += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
	}
	return (nd);
}
