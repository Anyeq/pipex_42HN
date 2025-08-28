/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:50:53 by asando            #+#    #+#             */
/*   Updated: 2025/07/16 12:12:29 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	putstr_out(const char *s, int precision, t_prse *prse)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (precision != 0 && i == precision)
			return (i);
		if (ft_printchar(s[i], prse) == 0)
			return (-1);
		i++;
	}
	return (i);
}

static int	print_arg(t_prse *prse, const char *s)
{
	int	n_digit;

	n_digit = 0;
	if (prse->flag_dot == 1 && prse->precision == 0)
	{
		if (ft_printchar('\0', prse) == 0)
			return (-1);
		return (n_digit);
	}
	n_digit += putstr_out(s, prse->precision, prse);
	return (n_digit);
}

static int	null_case(t_prse *prse)
{
	int	nd;
	int	nstr;
	int	tmp_precision;

	nd = 0;
	nstr = 6;
	tmp_precision = prse->precision;
	if (prse->flag_dot == 1 && (prse->precision == 0 || prse->precision < nstr))
		nstr = 0;
	else if (prse->flag_dot == 1 && prse->precision > nstr)
		tmp_precision = 0;
	if (prse->flag_minus == 0)
	{
		nd += write_width(prse->width, tmp_precision, prse->flag_zero, nstr);
		nd += print_arg(prse, "(null)");
	}
	else if (prse->flag_minus == 1)
	{
		nd += print_arg(prse, "(null)");
		nd += write_width(prse->width, tmp_precision, prse->flag_zero, nstr);
	}
	if (prse->write_err == 1)
		return (-1);
	return (nd);
}

static int	print_str(const char *s, t_prse *prse, int precision, int len_str)
{
	int	n_digit;

	n_digit = 0;
	if (prse->flag_dot == 1 && prse->precision == 0)
		len_str = 0;
	if (prse->flag_minus == 0)
	{
		n_digit += write_width(prse->width, precision, 0, len_str);
		n_digit += print_arg(prse, s);
	}
	else if (prse->flag_minus == 1)
	{
		n_digit += print_arg(prse, s);
		n_digit += write_width(prse->width, precision, 0, len_str);
	}
	if (prse->write_err == 1)
		return (-1);
	return (n_digit);
}

int	ft_putstr(const char *s, t_prse *prse)
{
	int	n_digit;
	int	len_str;
	int	precision;

	if (s == NULL)
		return (null_case(prse));
	precision = prse->precision;
	n_digit = 0;
	len_str = ft_strlen(s);
	if (len_str > precision && precision != 0)
		len_str = 0;
	else if (len_str <= precision && precision != 0)
		precision = 0;
	n_digit += print_str(s, prse, precision, len_str);
	if (prse->write_err == 1)
		return (-1);
	return (n_digit);
}
