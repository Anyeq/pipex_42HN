/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:26:33 by asando            #+#    #+#             */
/*   Updated: 2025/03/13 20:46:57 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> Join a string from s2 to s1
 * CALLED FUNCTION
 * ==> malloc(stdlib), ft_strlcpy(libft), ft_strlcat(libft), ft_strlen(libft)
 * PARAMETER (n = 3)
 * ==> 1.const char * 2.const char *
 * WORK
 * ==> Count how many character in total
 * ==> allocate memory
 * ==> copy the first string to a new allocated memory
 * ==> Concat the sacond string
 * RETURN
 * ==> A new string (combination)
 * REFERENCE
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result_str;
	size_t	s1_len;
	size_t	s2_len;
	int		total_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len + 1;
	result_str = malloc(total_len * sizeof(char));
	if (result_str == NULL)
		return (NULL);
	ft_strlcpy(result_str, s1, s1_len + 1);
	ft_strlcat(result_str, s2, total_len);
	return (result_str);
}
