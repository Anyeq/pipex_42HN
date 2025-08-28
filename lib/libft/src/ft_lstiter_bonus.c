/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:53:27 by asando            #+#    #+#             */
/*   Updated: 2025/03/17 13:56:40 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> traverse till the end of node and do some function to the node content
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 1)
 * ==> 1.t_list * 2. void
 * WORK
 * ==> traverse linklist and do action to the node content
 * ==> using parameter 2 do action with node content
 * RETURN
 * ==> none
 * REFERENCE
 * ==> link list data structure
 * ==> high order function
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
