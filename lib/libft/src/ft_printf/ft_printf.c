/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:22:55 by asando            #+#    #+#             */
/*   Updated: 2025/07/15 16:32:27 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_arg(const char *fmt, t_prse *prse, va_list args, int *iter)
{
	int	i;
	int	n_char;

	n_char = 0;
	i = 1;
	i += parse_format(&fmt[i], prse);
	if (ft_isalpha(fmt[i]) || fmt[i] == '%')
		n_char = write_arg(fmt[i], args, prse, &i);
	if (prse->write_err == 1)
		return (-1);
	*iter += i;
	return (n_char);
}

static int	printf_out(const char *fmt, int *i, int *n_char, t_prse *prse_rslt)
{
	if (prse_rslt->write_err != 1)
	{
		if (fmt[*i] == '\0')
			return (0);
		else if (ft_printchar(fmt[*i], prse_rslt) == 0)
			return (-1);
		*i += 1;
		*n_char += 1;
		return (1);
	}
	return (-1);
}

static int	check_format(const char *format)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (!ft_isalpha(format[i]) && format[i] != '%')
			{
				if (format[i] == '\0')
					return (-1);
				i++;
			}
		}
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		n_char;
	va_list	arg_list;
	t_prse	*prse;

	i = 0;
	n_char = check_format(format);
	prse = malloc(sizeof(t_prse));
	if (!prse)
		return (-1);
	prse->write_err = 0;
	va_start(arg_list, format);
	while (format[i] != '\0' && n_char >= 0)
	{
		while (format[i] == '%' && format[i] != '\0' && prse->write_err != 1)
			n_char += print_arg(&format[i], prse, arg_list, &i);
		if (printf_out(format, &i, &n_char, prse) < 0)
			n_char = -1;
	}
	free(prse);
	va_end(arg_list);
	return (n_char);
}
