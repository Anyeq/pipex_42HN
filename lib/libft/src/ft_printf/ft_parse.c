/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:58:26 by asando            #+#    #+#             */
/*   Updated: 2025/07/16 12:10:56 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

//%[argument$][flags][width][.precision][length modifier]conversion
static int	count_width_precision(const char *fmt_str, t_prse *prse)
{
	int	i;

	i = 0;
	if (fmt_str[i] == '.')
	{
		prse->flag_dot = 1;
		i++;
		while (ft_isdigit(fmt_str[i]))
		{
			prse->precision = 10 * prse->precision + (fmt_str[i] - '0');
			i++;
		}
		return (i);
	}
	while (ft_isdigit(fmt_str[i]))
	{
		prse->width = 10 * prse->width + (fmt_str[i] - '0');
		i++;
	}
	return (i);
}

static void	prse_init(t_prse *prse)
{
	prse->width = 0;
	prse->precision = 0;
	prse->flag_zero = 0;
	prse->flag_dot = 0;
	prse->flag_minus = 0;
	prse->flag_space = 0;
	prse->flag_plus = 0;
	prse->flag_hashtag = 0;
	prse->unsigned_int = 0;
	prse->write_err = 0;
}

static int	set_flags(const char *fmt_str, t_prse *prse)
{
	int	i;

	i = 0;
	if (!ft_isalnum(fmt_str[i]) || fmt_str[i] == '0')
	{
		if (fmt_str[i] == '0')
			prse->flag_zero = 1;
		else if (fmt_str[i] == '-')
			prse->flag_minus = 1;
		else if (fmt_str[i] == '#')
			prse->flag_hashtag = 1;
		else if (fmt_str[i] == ' ')
			prse->flag_space = 1;
		else if (fmt_str[i] == '+')
			prse->flag_plus = 1;
		else if (fmt_str[i] == '.')
			prse->flag_dot = 1;
		i++;
	}
	return (i);
}

int	parse_format(const char *fmt_str, t_prse *prse_rslt)
{
	int		i;

	i = 0;
	prse_init(prse_rslt);
	while (!ft_isalpha(fmt_str[i]) && fmt_str[i] != '%' && fmt_str[i] != '\0')
	{
		if (prse_rslt->width == 0 && (fmt_str[i] != '.' || fmt_str[i] == '0'))
			i += set_flags(&fmt_str[i], prse_rslt);
		if (fmt_str[i] == '.' || ft_isdigit(fmt_str[i]))
			i += count_width_precision(&fmt_str[i], prse_rslt);
	}
	return (i);
}
