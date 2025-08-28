/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:16:47 by asando            #+#    #+#             */
/*   Updated: 2025/03/12 15:32:27 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> duplicate str
 * CALLED FUNCTION
 * ==> malloc(stdlib), ft_strlen(libft), ft_strlcpy(libft)
 * PARAMETER (n = 1)
 * ==> 1.const char *
 * WORK
 * ==> duplicate everything from src to a new memory
 * RETURN
 * ==> address of a new memory
 * REFERENCE
 * ==> strdup in string.h
*/
char	*ft_strdup(const char *str)
{
	char				*str_new;
	long unsigned int	len;

	len = ft_strlen(str);
	str_new = malloc((len + 1) * sizeof(char));
	if (str_new == NULL)
		return (NULL);
	ft_strlcpy(str_new, str, len + 1);
	return (str_new);
}
