/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 07:28:59 by asando            #+#    #+#             */
/*   Updated: 2025/08/07 19:21:29 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> convert string to int (ex: "123" become 123 as integer) 
 * CALLED FUNCTION
 * ==> ft_isdigit(libft)
 * PARAMETER (n = 1)
 * ==> 1.String (ex = "123") '%'
 * WORK
 * ==> take parameter and convert it to int by subs with '0'
 * RETURN
 * ==> int
 * REFERENCE
 * ==> atoi in stdlib.h
*/
int	ft_atoi(const char *nptr)
{
	int	num;
	int	i;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10 + ((nptr[i] - '0') * sign);
		i++;
	}
	return (num);
}
