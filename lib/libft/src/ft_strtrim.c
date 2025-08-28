/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:48:46 by asando            #+#    #+#             */
/*   Updated: 2025/03/21 14:39:07 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> trim set from src
 * CALLED FUNCTION
 * ==> check_str(l), ft_strdup(libft.h), malloc(stdlib.h), copy_str(l)
 * PARAMETER (n = 4)
 * ==> 1.char const *, 2.char const *
 * WORK
 * ==> check if src contain set
 * ==> based on condition copy only src without trim to result_str
 * RETURN
 * ==> NULL if variable allocated is null or allocation failed
 * ==> cleaned (without set) string
 * REFERENCE
 * ==>
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	s1_len;
	size_t	n_char_cp;
	size_t	i;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
		i++;
	while (ft_strchr(set, s1[s1_len - 1]) && s1_len > i)
		s1_len = s1_len - 1;
	n_char_cp = s1_len - i + 1;
	res = malloc(n_char_cp * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &s1[i], n_char_cp);
	return (res);
}
