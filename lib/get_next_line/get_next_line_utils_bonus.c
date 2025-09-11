/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:41:22 by asando            #+#    #+#             */
/*   Updated: 2025/07/23 19:45:31 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	err_check(int fd, char **storage)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (*storage)
		{
			free(*storage);
			*storage = NULL;
		}
		return (0);
	}
	return (1);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;
	int		len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (!src)
		return (0);
	if (len == 0)
		return (len_src);
	while ((src[i] != '\0') && i < (len - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len_src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result_str;
	size_t	s1_len;
	size_t	s2_len;
	int		total_len;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len + 1;
	result_str = malloc(total_len * sizeof(char));
	if (result_str == NULL)
		return (NULL);
	ft_strlcpy(result_str, s1, s1_len + 1);
	i = 0;
	while (s2[i])
	{
		result_str[i + s1_len] = s2[i];
		i++;
	}
	result_str[i + s1_len] = '\0';
	return (result_str);
}
