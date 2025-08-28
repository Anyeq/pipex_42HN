/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:23:29 by asando            #+#    #+#             */
/*   Updated: 2025/03/11 08:27:22 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * FUNCTION (G)
 * ==> Change charachter input to uppercase 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 1)
 * ==> 1.int
 * WORK
 * ==> charachter is substracted by 32 to get the ASCII num of uppercase
 * RETURN
 * ==> uppercase character
 * REFERENCE
 * ==> toupper in ctype.h
*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
