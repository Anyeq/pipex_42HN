/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:58:38 by asando            #+#    #+#             */
/*   Updated: 2025/03/10 21:00:47 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * FUNCTION (G)
 * ==> Check if parameter given is an alphanumeric 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 1)
 * ==> 1.int
 * WORK
 * ==> check if parameter fall into alphanum range in ASCII table
 * RETURN
 * ==> bigger than 0 if alnum and 0 if none alnum
 * REFERENCE
 * ==> isalnum in ctype.h
*/
int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (8);
	else if (c >= 'A' && c <= 'z')
	{
		if (c <= 'Z' || c >= 'a')
			return (8);
	}
	return (0);
}
