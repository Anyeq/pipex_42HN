/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:30:46 by asando            #+#    #+#             */
/*   Updated: 2025/03/21 16:14:32 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> create new list type struct (link list)
 * CALLED FUNCTION
 * ==> malloc(stdlib)
 * PARAMETER (n = 1)
 * ==> 1.void *
 * WORK
 * ==> allocate memory for a struct
 * ==> fill up the strct component with conten and next pointing to null
 * RETURN
 * ==> the address of new list
 * REFERENCE
 * ==> link list data structure
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
