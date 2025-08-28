/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:49:48 by asando            #+#    #+#             */
/*   Updated: 2025/03/19 13:57:43 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> add list into linklist structure in the front
 * CALLED FUNCTION
 * ==> t_list structure in header
 * PARAMETER (n = 1)
 * ==> 1. t_list structure, t_list new
 * WORK
 * ==> take a new t_list variable and add it to the front of link list
 * RETURN
 * ==> none
 * REFERENCE
 * ==> link_list data structure
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
