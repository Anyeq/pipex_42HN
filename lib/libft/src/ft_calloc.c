/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:00:15 by asando            #+#    #+#             */
/*   Updated: 2025/03/19 13:27:33 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> Allocate memmory and fill default value by 0 
 * CALLED FUNCTION
 * ==> malloc, ft_memset
 * PARAMETER (n = 2)
 * ==> 1.n member, 2.size of each member
 * WORK
 * ==> allocate memory n member x size and set value by 0
 * RETURN
 * ==> none
 * REFERENCE
 * ==> calloc in stdlib.h
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	arr = malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	ft_memset(arr, 0, (nmemb * size));
	return (arr);
}
