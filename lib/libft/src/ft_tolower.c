/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:28:17 by asando            #+#    #+#             */
/*   Updated: 2025/03/11 08:31:27 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * FUNCTION (G)
 * ==> Change input character to lowercase 
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 1)
 * ==> 1.int
 * WORK
 * ==> add 32 to character to get ASCII number of lowercase character
 * RETURN
 * ==> Lowercase character
 * REFERENCE
 * ==> tolower in ctype.h
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
