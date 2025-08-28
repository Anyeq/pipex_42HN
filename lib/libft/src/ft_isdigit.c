/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:53:15 by asando            #+#    #+#             */
/*   Updated: 2025/03/10 20:57:56 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * FUNCTION (G)
 * ==> Check if parameter given is an digit 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 1)
 * ==> 1. int
 * WORK
 * ==> check if parameter fall into digit range in ASCII table
 * RETURN
 * ==> bigger than 0 if digit and 0 if none digit
 * REFERENCE
 * ==> isdigit in ctype.h
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}
