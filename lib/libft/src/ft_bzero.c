/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:45:23 by asando            #+#    #+#             */
/*   Updated: 2025/03/12 14:45:50 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> Erase data in memory by writing '\0' 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 2)
 * ==> 1.String (any data minimum has len data), 2.len of data erased
 * WORK
 * ==> take the string address and writing '\0' as many as len
 * RETURN
 * ==> none, it change original parameter
 * REFERENCE
 * ==> bzero in string.h
*/
void	ft_bzero(void *str, size_t n)
{
	char	*strs;
	size_t	i;

	i = 0;
	strs = (char *)str;
	while (i < n)
	{
		*(strs + i) = 0;
		i++;
	}
	return ;
}
