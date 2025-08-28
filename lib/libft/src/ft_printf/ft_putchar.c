/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:50:53 by asando            #+#    #+#             */
/*   Updated: 2025/07/15 11:31:27 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(unsigned int s, t_prse *prse)
{
	int	n_digit;

	n_digit = 0;
	if (prse->flag_minus == 0)
	{
		n_digit += write_width(prse->width, prse->precision, 0, 1);
		if (ft_printchar(s, prse) == 0)
			return (0);
		return (n_digit + 1);
	}
	else if (prse->flag_minus == 1)
	{
		if (ft_printchar(s, prse) == 0)
			return (0);
		n_digit += write_width(prse->width, prse->precision, 0, 1);
		return (n_digit + 1);
	}
	if (ft_printchar(s, prse) == 0)
		return (0);
	return (n_digit + 1);
}
