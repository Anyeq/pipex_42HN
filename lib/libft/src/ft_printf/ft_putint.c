/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2025/07/18 10:29:30 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	putint_out(int n, t_prse *prse)
{
	char	c;

	if (n == INT_MIN)
	{
		if (write(1, "2147483648", 10) < 10)
			prse->write_err = 1;
		return ;
	}
	if (n < 0)
		n = n * -1;
	if (n / 10 > 0 && prse->write_err != 1)
		putint_out(n / 10, prse);
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

static void	width_precision_sign(int n, int f_plus, int *nstr, int *prcs)
{
	if (n < 0 || f_plus == 1)
	{
		*nstr += 1;
		*prcs += 1;
	}
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
		putint_out(n, prse);
	if (prse->write_err == 1)
		return (-1);
	return (1);
}

static int	add_format(t_prse *prse, int n, int prcs, int nstr)
{
	int	nchar;
	int	nstr_prcs;

	nchar = 0;
	nstr_prcs = nstr;
	if (n < 0 || prse->flag_space == 1)
		nstr_prcs = nstr - 1;
	if (prse->flag_zero == 1 && prse->flag_dot == 0)
	{
		nchar += write_sign(prse, n, NULL);
		nchar += write_width(prse->width, prcs, prse->flag_zero, nstr);
		if (print_arg(n, prse->flag_dot, prse->precision, prse) != 1)
			return (-1);
	}
	else
	{
		nchar += write_width(prse->width, prcs, 0, nstr);
		nchar += write_sign(prse, n, NULL);
		nchar += write_precision(prse->precision, nstr_prcs);
		if (print_arg(n, prse->flag_dot, prse->precision, prse) != 1)
			return (-1);
	}
	if (n == 0 && prse->precision == 0 && prse->flag_dot == 1)
		nchar -= 1;
	return (nchar);
}

int	ft_putint(int n, t_prse *prse)
{
	int	nd;
	int	nstr;
	int	nstr_prcs;
	int	prcs;

	nstr = count_digit_int(n);
	nstr_prcs = nstr;
	nd = nstr;
	prcs = prse->precision;
	width_precision_sign(n, prse->flag_plus, &nstr, &prcs);
	if (n >= 0)
		nd += write_space(prse, &nstr);
	if (prse->flag_minus == 0)
		nd += add_format(prse, n, prcs, nstr);
	else if (prse->flag_minus == 1)
	{
		nd += write_sign(prse, n, NULL);
		nd += write_precision(prse->precision, nstr_prcs);
		print_arg(n, prse->flag_dot, prse->precision, prse);
		nd += write_width(prse->width, prcs, prse->flag_zero, nstr);
	}
	if (prse->write_err == 1)
		return (-1);
	return (nd);
}
