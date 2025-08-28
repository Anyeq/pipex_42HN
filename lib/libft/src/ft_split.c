/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:14:22 by asando            #+#    #+#             */
/*   Updated: 2025/03/23 21:19:12 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (L)
 * ==> count how many part it would be when we split it by delimiter
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 2)
 * ==> 1. const char * 2. char
 * WORK
 * ==> count how many delimiter inside a src
 * RETURN
 * ==> number of delimiter could be intepreted as number of part after split
 * REFERENCE
 * ==>
*/
static size_t	count_word(const char *str, char delimiter)
{
	size_t	res;
	int		in_word;
	size_t	i;

	res = 0;
	i = 0;
	in_word = 1;
	while (delimiter != '\0' && str[i] != '\0')
	{
		if (str[i] != delimiter && in_word)
		{
			res++;
			in_word = 0;
		}
		if (str[i] == delimiter)
			in_word = 1;
		i++;
	}
	if (delimiter == '\0')
		res++;
	return (res);
}

/*
 * FUNCTION (L)
 * ==> copy the word to a new allocated memory before delimiter and \0
 * CALLED FUNCTION
 * ==> malloc(stdlib.h), ft_strlcpy(libft.h)
 * PARAMETER (n = 2)
 * ==> 1. const char * 2. char
 * WORK
 * ==> traverse trough the src until it reach delimiter or \0
 * ==> copying everything it traversed trough a new allocated memory
 * RETURN
 * ==> NULL if allocation fail
 * ==> addres of a new allocated memory consist of part of src before delimiter
 * REFERENCE
 * ==>
*/
static char	*keep_word(char const *s, char c)
{
	char			*buff;
	unsigned int	not_delimiter;

	not_delimiter = 0;
	if (!s)
		return (NULL);
	while (s[not_delimiter] != c && s[not_delimiter] != '\0')
		not_delimiter++;
	if (not_delimiter == 0)
		return (NULL);
	buff = malloc((not_delimiter + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	ft_strlcpy(buff, s, not_delimiter + 1);
	return (buff);
}

/*
 * FUNCTION (l)
 * ==> find a charachter that is not delimiter to tackel multiple delimiter
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 2)
 * ==> 1. const char * 2. char
 * WORK
 * ==> traverse string and find the charachter that is not delimiter
 * RETURN
 * ==> NULL if non delimiter is not found
 * ==> addres of a non delimiter charachter
 * REFERENCE
 * ==>
*/
static char	*find_word(char const *s, char c)
{
	unsigned int	i;
	char			*str;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*
 * FUNCTION (l)
 * ==> clean memorry allocation if it failed to allocate
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 2)
 * ==> 1. char ** 2. size_t
 * WORK
 * ==> check if allocation return NULL
 * ==> if yes traverse every element of array and free it
 * ==> and the end free the array it self
 * RETURN
 * ==> 1 if free is called
 * ==> 0 if free is not called or allocation success
 * REFERENCE
 * ==>
* */
static int	clean_if_null(char **str, size_t i)
{
	if (!str[i])
	{
		while (i > 0)
			free(str[--i]);
		free(str);
		return (1);
	}
	return (0);
}

/*
 * FUNCTION (G)
 * ==> split string base on delimiter
 * CALLED FUNCTION
 * ==> count_word(l), malloc(stdlib.h), find_word(l), keep_word(l)
 * ==> clean_if_null(l), ft_strchr(libft.h)
 * PARAMETER (n = 2)
 * ==> 1. char const * 2. char
 * WORK
 * ==> count how many split part would be created
 * ==> allocate memory for array
 * ==> keep part and put it into array
 * RETURN
 * ==> pointer to array if success
 * ==> NULL if problem occure
 * REFERENCE
 * ==>
* */
char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*temp;
	size_t	n_word;
	size_t	n_arr;

	if (!s)
		return (NULL);
	n_word = count_word(s, c);
	res = malloc((n_word + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	n_arr = 0;
	temp = (char *)s;
	while (n_arr < n_word && n_word > 0 && s[0] != '\0')
	{
		temp = find_word(temp, c);
		res[n_arr] = keep_word(temp, c);
		if (clean_if_null(res, n_arr))
			return (NULL);
		temp = ft_strchr(temp, c);
		n_arr++;
	}
	res[n_arr] = NULL;
	return (res);
}
