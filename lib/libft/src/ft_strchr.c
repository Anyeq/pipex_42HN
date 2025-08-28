/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:36:50 by asando            #+#    #+#             */
/*   Updated: 2025/03/19 08:33:51 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> find a character inside a list of character given 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 2)
 * ==> 1.char * 2.int
 * WORK
 * ==> traversing through the whole list of character
 * ==> comparing ASCII every character with character we are looking for
 * ==> stop when it find the character or it reach \0
 * RETURN
 * ==> the address of the character or NULL when it is not found
 * REFERENCE
 * ==> strchr in string.h
*/
char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*str_uc;

	str_uc = (char *)str;
	i = 0;
	while (str_uc[i] != '\0')
	{
		if ((unsigned char)str_uc[i] == (unsigned char)c)
			return (&str_uc[i]);
		i++;
	}
	if ((unsigned char)str_uc[i] == (unsigned char)c)
		return (&str_uc[i]);
	return (NULL);
}
