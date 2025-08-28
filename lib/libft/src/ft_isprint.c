/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:07:43 by asando            #+#    #+#             */
/*   Updated: 2025/03/10 21:08:18 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * FUNCTION (G)
 * ==> Check if parameter given is an printable ascii 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 1)
 * ==> 1.int
 * WORK
 * ==> check if parameter fall into printable range in ASCII table
 * RETURN
 * ==> bigger than 0 if printable and 0 if none printable
 * REFERENCE
 * ==> isprint in ctype.h
*/
int	ft_isprint(int c)
{
	if (c >= ' ' && c < 127)
		return (16384);
	return (0);
}
