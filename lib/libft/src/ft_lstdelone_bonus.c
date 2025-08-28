/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:06:07 by asando            #+#    #+#             */
/*   Updated: 2025/03/17 12:10:49 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> delete one linklist node
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 2)
 * ==> 1.t_list *, 2.function that return void
 * WORK
 * ==> take the addres of node to delete
 * ==> delete it using function provide in parameter 2
 * RETURN
 * ==> none
 * REFERENCE
 * ==> link list data structure
 * ==> high order function
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}
