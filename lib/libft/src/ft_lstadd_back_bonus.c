/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:29:03 by asando            #+#    #+#             */
/*   Updated: 2025/03/17 11:05:14 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> add list into linklist structure in the back
 * CALLED FUNCTION
 * ==> t_list structure in header
 * PARAMETER (n = 1)
 * ==> 1. t_list structure, t_list new
 * WORK
 * ==> take a new t_list variable and check if t_list structure is empty
 * ==> if not empty traverse to the end of link list and add new structure
 * RETURN
 * ==> none
 * REFERENCE
 * ==> link_list data structure
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}
