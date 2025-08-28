/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:50:53 by asando            #+#    #+#             */
/*   Updated: 2025/03/14 17:00:06 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> put string into file decriptor provided
 * CALLED FUNCTION
 * ==> ft_puchar_fd(libft.h)
 * PARAMETER (n = 2)
 * ==> 1.char 2.int
 * WORK
 * ==> put string into fd by calling fd_puchar_fd to every character
 * RETURN
 * ==> none
 * REFERENCE
 * ==>
*/
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	return ;
}
