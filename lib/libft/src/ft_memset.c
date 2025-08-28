/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 07:33:42 by asando            #+#    #+#             */
/*   Updated: 2025/03/18 14:43:19 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> Set a memory to specific int 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 3)
 * ==> 1.char * 2.char * 3.size_t
 * WORK
 * ==> traversing through the whole list of character
 * ==> comparing ASCII every character with other list of characher
 * ==> stop when it find there is different or it reach n
 * RETURN
 * ==> the ASCII different between 2 character
 * REFERENCE
 * ==> strncmp in string.h
*/
void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*strs;

	strs = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		*(strs + i) = (unsigned char)c;
		i++;
	}
	return (str);
}
