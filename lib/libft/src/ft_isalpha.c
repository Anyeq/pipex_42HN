/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:41:06 by asando            #+#    #+#             */
/*   Updated: 2025/03/10 20:51:23 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * FUNCTION (G)
 * ==> Check if parameter given is an alphabet 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 1)
 * ==> 1. int
 * WORK
 * ==> check if parameter fall into alphabet range in ASCII table
 * RETURN
 * ==> bigger than 0 if alnum and 0 if none alnum
 * REFERENCE
 * ==> isalpha in ctype.h
*/
int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'z')
	{
		if (c <= 'Z' || c >= 'a')
			return (1024);
	}
	return (0);
}
