/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:27:42 by asando            #+#    #+#             */
/*   Updated: 2025/03/19 14:45:18 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> copy the content of a memory from src to dst
 * CALLED FUNCTION
 * ==> ft_strlen(libft)
 * PARAMETER (n = 3)
 * ==> 1.void * 2.void * 3.size_t
 * WORK
 * ==> traversing through the whole list of character
 * ==> copy every character to dest
 * ==> stop when it reach n or reach the end of source or dst full
 * RETURN
 * ==> the dest
 * REFERENCE
 * ==> memcpy in string.h
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*str_dest;
	const char	*str_src;
	size_t		i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	str_dest = (char *)dest;
	str_src = (const char *)src;
	while (i < n)
	{
		*(str_dest + i) = *(str_src + i);
		i++;
	}
	return (dest);
}
