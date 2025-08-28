/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:52:12 by asando            #+#    #+#             */
/*   Updated: 2025/03/19 08:35:50 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> find a character inside a list of character given from the back 
 * CALLED FUNCTION
 * ==> ft_strlen(libft)
 * PARAMETER (n = 2)
 * ==> 1.char * 2.int
 * WORK
 * ==> getting how many character is in the input using ft_strlen
 * ==> traversing through the whole list of character from the back
 * ==> comparing ASCII every character with character we are looking for
 * ==> stop when it find the character or it is pointing to the first character
 * RETURN
 * ==> the address of the character or NULL when it is not found
 * REFERENCE
 * ==> strrchr in string.h
*/
char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		str_len;
	char	*str_uc;

	i = 0;
	str_len = ft_strlen(str);
	str_uc = (char *)str;
	while ((str_len - i) >= 0)
	{
		if ((unsigned char)str_uc[str_len - i] == (unsigned char)c)
			return (&str_uc[str_len - i]);
		i++;
	}
	return (NULL);
}
