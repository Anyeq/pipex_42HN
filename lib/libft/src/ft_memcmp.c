/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:51:58 by asando            #+#    #+#             */
/*   Updated: 2025/03/19 08:55:00 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> Compare a charachter inside a s1 and s2 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 3)
 * ==> 1.char *  2.char * c 3.size_t
 * WORK
 * ==> traversing through the whole list of character
 * ==> comparing ASCII every character in s1 to s2
 * ==> stop when it reach n or it find the different
 * RETURN
 * ==> the different betwen 2 different character
 * ==> 0 if there is no different
 * REFERENCE
 * ==> memchr in string.h
*/
int	ft_memcmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] - (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
