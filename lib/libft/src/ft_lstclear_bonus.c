/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:11:13 by asando            #+#    #+#             */
/*   Updated: 2025/03/19 13:43:33 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> clear link list
 * CALLED FUNCTION
 * ==> t_list structure in header, free (stdlib.h)
 * PARAMETER (n = 1)
 * ==> 1. t_list structure, 2. a function address
 * WORK
 * ==> take an address of link list data structure, use a parameter del
 *    to del data, traverse in the link list till the end of link list
 *    after deleting free the memory
 * RETURN
 * ==> none
 * REFERENCE
 * ==> link_list data structure
 * ==> high order function 
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*temp;

	if (lst == NULL || *lst == NULL)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}
