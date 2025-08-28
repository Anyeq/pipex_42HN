/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:54:08 by asando            #+#    #+#             */
/*   Updated: 2025/03/19 13:54:13 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> modified component s using funcion providied in the second argument
 * CALLED FUNCTION
 * ==> malloc(stdlib), ft_strlen(libft)
 * PARAMETER (n = 2)
 * ==> 1.char const * 2.function that return char
 * WORK
 * ==> travesse s and using the function provided in parameter change s
 * ==> put it on a result
 * RETURN
 * ==> address of a new memory
 * REFERENCE
 * ==>
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;
	int		len;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
