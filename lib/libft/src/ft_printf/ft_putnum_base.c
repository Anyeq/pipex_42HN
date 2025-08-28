/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2025/07/18 10:47:21 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	putnumbase_out(unsigned int n, int nbase,
	const char *base, t_prse *prse)
{
	if (n == 0)
	{
		if (write(1, "0", 1) < 1)
		{
			prse->write_err = 1;
			return ;
		}
		return ;
	}
	if (n / nbase > 0 && prse->write_err != 1)
		putnumbase_out(n / nbase, nbase, base, prse);
	if (prse->write_err != 1)
	{
		if (write(1, &base[n % nbase], 1) < 1)
		{
			prse->write_err = 1;
			return ;
		}
	}
	return ;
}

static char	*sign_choose(t_prse *prse, unsigned int num, const char *base)
{
	char	*str;

	str = NULL;
	if (num == 0)
		return (str);
	if (prse->flag_hashtag == 1 && base[10] == 'A')
		str = "0X";
	else if (prse->flag_hashtag == 1 && base[10] == 'a')
		str = "0x";
	return (str);
}

static int	print_arg(unsigned int n, int nbase, const char *base, t_prse *prse)
{
	char	char_print;

	char_print = ' ';
	if (prse->width == 0)
		char_print = '\0';
	if (prse->flag_dot == 1 && prse->precision == 0 && n == 0)
	{
		if (ft_printchar(char_print, prse) == 0)
			return (-1);
		return (1);
	}
	if (prse->write_err != 1)
		putnumbase_out(n, nbase, base, prse);
	if (prse->write_err == 1)
		return (-1);
	return (1);
}

static void	condition_init(unsigned int *n, int *nd, t_prse *prse)
{
	if (*n == 0 && prse->precision == 0 && prse->flag_dot == 1)
		*nd = 0;
	prse->unsigned_int = 1;
	if (prse->flag_dot == 1)
		prse->flag_zero = 0;
}

int	ft_putnum_base(unsigned int n, int nbase, const char *base, t_prse *prse)
{
	int		nstr;
	int		nd;
	char	*sign;

	sign = sign_choose(prse, n, base);
	nstr = count_digit_nbase(n, nbase);
	nd = nstr;
	condition_init(&n, &nd, prse);
	if (prse->flag_minus == 0)
	{
		nd += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
		nd += write_sign(prse, 42, sign);
		nd += write_precision(prse->precision, nstr);
		print_arg(n, nbase, base, prse);
	}
	else if (prse->flag_minus == 1)
	{
		nd += write_sign(prse, 42, sign);
		nd += write_precision(prse->precision, nstr);
		print_arg(n, nbase, base, prse);
		nd += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
	}
	if (prse->write_err == 1)
		return (-1);
	return (nd);
}
