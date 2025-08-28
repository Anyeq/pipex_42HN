/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:47:53 by asando            #+#    #+#             */
/*   Updated: 2025/03/19 13:14:48 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> create a sub string from string
 * CALLED FUNCTION
 * ==> malloc(stdlib), ft_strlcpy(libft)
 * PARAMETER (n = 3)
 * ==> 1.const char * 2.unsigned int, 3.size_t
 * WORK
 * ==> copy the string from start to a new address as many as n
 * RETURN
 * ==> address of a new memory
 * REFERENCE
 * ==> substr in string c++
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
	{
		sub_str = malloc(1);
		if (!sub_str)
			return (NULL);
		sub_str[0] = 0;
		return (sub_str);
	}
	if (len > (str_len - start))
		len = str_len - start;
	sub_str = malloc((len + 1) * sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	ft_strlcpy(sub_str, &s[start], len + 1);
	return (sub_str);
}
