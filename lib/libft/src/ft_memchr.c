/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:15:30 by asando            #+#    #+#             */
/*   Updated: 2025/03/18 16:34:02 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> Find a characther inside a list of character 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 3)
 * ==> 1.void  2.int c 3.size_t
 * WORK
 * ==> traversing through the whole list of character
 * ==> comparing ASCII every character with other list of characher
 * ==> stop when it reach n or it find the same character
 * RETURN
 * ==> the address of character that being found
 * REFERENCE
 * ==> memchr in string.h
*/
void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*strs;

	if (n == 0)
		return (NULL);
	strs = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (strs[i] == (unsigned char)c)
			return (&strs[i]);
		i++;
	}
	if (i < n && strs[i] == (unsigned char)c)
		return (&strs[i]);
	return (NULL);
}
