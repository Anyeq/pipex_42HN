/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:34:54 by asando            #+#    #+#             */
/*   Updated: 2025/03/21 14:39:27 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> Find a set of charachter inside a list of character 
 * CALLED FUNCTION
 * ==> ft_strlen(libft)
 * PARAMETER (n = 3)
 * ==> 1.const char *  2.const char * c 3.size_t
 * WORK
 * ==> traversing through the whole list of character
 * ==> comparing ASCII every character with the set of charachter
 * ==> stop when it has the set of charachter
 * RETURN
 * ==> the address of set of charachter found
 * REFERENCE
 * ==> strnstr in string.h
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	size_t	j;

	i = 0;
	j = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)&big[0]);
	while ((big[i] != '\0') && (i < len))
	{
		while (big[i] != '\0' && little[j] != '\0'
			&& big[i] == little[j] && (i < len))
		{
			i++;
			j++;
		}
		i = i - j;
		if (j == little_len)
			return ((char *)&big[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
