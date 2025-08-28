/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:46:20 by asando            #+#    #+#             */
/*   Updated: 2025/03/21 13:39:13 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> cpoying the data from src to dest 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 3)
 * ==> 1.void *, 2.const void *, 3.size_t
 * WORK
 * ==> copying the source into the dstination
 * ==> stop when it reach n
 * RETURN
 * ==> destination
 * REFERENCE
 * ==> memmove in string.h
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (dest);
	i = 0;
	if (src < dest && dest < (src + n))
	{
		i = n;
		while (i != 0)
		{
			i = i - 1;
			((char *)dest)[i] = ((char *)src)[i];
		}
	}
	else
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}
