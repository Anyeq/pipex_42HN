/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:01:30 by asando            #+#    #+#             */
/*   Updated: 2025/07/21 10:34:05 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	putptr_out(uintptr_t n, t_prse *prse)
{
	if (n / 16 > 0)
		putptr_out(n / 16, prse);
	if (write(STDOUT_FILENO, &("0123456789abcdef"[n % 16]), 1) < 1)
	{
		prse->write_err = 1;
		return ;
	}
	return ;
}

static int	null_case(t_prse *prse)
{
	int	nd;

	nd = PTRNULL_NUM;
	if ((prse->width > 0 || prse->precision > 0) && prse->flag_minus == 0)
	{
		nd += write_width(prse->width, prse->precision, prse->flag_zero, 3);
		if (write(STDOUT_FILENO, PTRNULL, PTRNULL_NUM) < PTRNULL_NUM)
			prse->write_err = 1;
		return (nd);
	}
	else if ((prse->width > 0 || prse->precision > 0) && prse->flag_minus == 1)
	{
		if (write(STDOUT_FILENO, PTRNULL, PTRNULL_NUM) < PTRNULL_NUM)
			prse->write_err = 1;
		nd += write_width(prse->width, prse->precision, prse->flag_zero, 3);
		return (nd);
	}
	else
	{
		if (write(STDOUT_FILENO, PTRNULL, PTRNULL_NUM) < PTRNULL_NUM)
			prse->write_err = 1;
		return (nd);
	}
	return (nd);
}

static int	putptr_main(void *n, t_prse *prse)
{
	int	n_digit;

	n_digit = 0;
	if (prse->write_err == 1)
		return (-1);
	if (n == NULL)
	{
		n_digit += null_case(prse);
		if (prse->write_err == 1)
			return (-1);
		return (n_digit);
	}
	n_digit = count_digit_ptr((uintptr_t)n);
	putptr_out((uintptr_t)n, prse);
	if (prse->write_err == 1)
		return (-1);
	return (n_digit);
}

static int	count_nstr(void *n, int precision)
{
	int			main_digit;
	uintptr_t	num;

	main_digit = 0;
	num = (uintptr_t)n;
	if (n == NULL)
		return (main_digit);
	while (num / 16 > 0)
	{
		num /= 16;
		main_digit++;
	}
	main_digit++;
	if (precision > main_digit)
		main_digit = precision;
	return (main_digit + 2);
}

int	ft_putptr(void *n, t_prse *prse)
{
	int	nd;
	int	nstr;

	nstr = count_nstr(n, prse->precision);
	nd = 0;
	nd += write_space(prse, &nstr);
	if (prse->flag_minus == 0 && n != NULL)
	{
		nd += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
		nd += write_sign(prse, 42, "0x");
		nd += write_precision(prse->precision, nstr - 2);
		nd += putptr_main(n, prse);
	}
	else if (prse->flag_minus == 1 && n != NULL)
	{
		nd += write_sign(prse, 42, "0x");
		nd += write_precision(prse->precision, nstr - 2);
		nd += putptr_main(n, prse);
		nd += write_width(prse->width, prse->precision, prse->flag_zero, nstr);
	}
	else if (n == NULL)
		nd += putptr_main(n, prse);
	if (prse->write_err == 1)
		return (-1);
	return (nd);
}
