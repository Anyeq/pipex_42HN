/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:04:12 by asando            #+#    #+#             */
/*   Updated: 2025/03/10 21:06:36 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * FUNCTION (G)
 * ==> Check if parameter given is ascii 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 1)
 * ==> 1.int
 * WORK
 * ==> check if parameter fall into ASCII range in ASCII table
 * RETURN
 * ==> bigger than 0 if ascii and 0 if none ascii
 * REFERENCE
 * ==> isascii in ctype.h
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
