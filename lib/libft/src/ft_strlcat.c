/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 08:09:31 by asando            #+#    #+#             */
/*   Updated: 2025/03/18 14:41:02 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> Concatenate src into dest 
 * CALLED FUNCTION
 * ==> ft_strlen(libft)
 * PARAMETER (n = 3)
 * ==> 1.char * 2.char * 3.size_t
 * WORK
 * ==> traverse src
 * ==> concatenate src into destination
 * ==> Stop conct when it reach \0 or destination memory used until end - 1
 * RETURN
 * ==> the len of destination after being concatenate
 * REFERENCE
 * ==> strlcat in string.h
*/
size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	total_len = dest_len + src_len;
	if (len <= dest_len)
		return (src_len + len);
	while (src[i] != '\0' && ((dest_len + i) < (len - 1)))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if ((dest_len + i) < len)
		dest[dest_len + i] = '\0';
	return (total_len);
}
