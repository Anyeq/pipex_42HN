/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_precision_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:40:56 by asando            #+#    #+#             */
/*   Updated: 2025/07/18 10:59:54 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	write_width(int width, int precision, int f_zero, int nstr)
{
	int	nchar;
	int	str_size;

	str_size = count_str_size(precision, nstr);
	nchar = 0;
	while (nchar < (width - str_size))
	{
		if (f_zero == 1)
			write(STDOUT_FILENO, "0", 1);
		else if (precision > 0 || f_zero == 0)
			write(STDOUT_FILENO, " ", 1);
		nchar++;
	}
	return (nchar);
}

int	write_precision(int precision, int nstr)
{
	int	nchar;

	nchar = 0;
	while (nchar < (precision - nstr))
	{
		write(STDOUT_FILENO, "0", 1);
		nchar++;
	}
	return (nchar);
}

int	write_sign(t_prse *prse, int num, char *sign)
{
	int	nchar;

	nchar = 0;
	if (prse->precision == 0 && prse->flag_dot == 1 && prse->unsigned_int == 1)
		return (nchar);
	if (num < 0)
	{
		if (write(STDOUT_FILENO, "-", 1) < 1)
			prse->write_err = 1;
		nchar++;
	}
	else if (num >= 0 && prse->flag_plus == 1 && prse->unsigned_int != 1)
	{
		write(STDOUT_FILENO, "+", 1);
		nchar++;
	}
	if (sign != NULL)
	{
		if (write(STDOUT_FILENO, sign, 2) < 2)
			prse->write_err = 1;
		nchar += 2;
	}
	return (nchar);
}

int	write_space(t_prse *prse, int *nstr)
{
	if (prse->flag_space == 1 && prse->flag_minus == 0 && prse->flag_plus == 0)
	{
		write(STDOUT_FILENO, " ", 1);
		if (nstr != NULL)
			*nstr += 1;
		return (1);
	}
	return (0);
}
