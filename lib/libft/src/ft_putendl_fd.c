/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:58:35 by asando            #+#    #+#             */
/*   Updated: 2025/03/14 17:00:25 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> put string into file decriptor provided and end with new line
 * CALLED FUNCTION
 * ==> ft_pustr_fd(libft.h)
 * PARAMETER (n = 2)
 * ==> 1.char * 2.int
 * WORK
 * ==> put string into fd by calling fd_putstr_fd and end it with \n
 * RETURN
 * ==> none
 * REFERENCE
 * ==>
*/
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
	return ;
}
