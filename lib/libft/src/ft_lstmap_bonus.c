/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:57:08 by asando            #+#    #+#             */
/*   Updated: 2025/03/21 16:41:35 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (l)
 * ==> check if function applied to lst work properly
 * CALLED FUNCTION
 * ==> ft_lstclear(libft)
 * PARAMETER (n = 3)
 * ==> 1.t_list ** 2. function 3.function
 * WORK
 * ==> check if parameter 2 is NULL
 * RETURN
 * ==> 1 if parameter 2 is NULL
 * ==> 0 if parameter 2 is not null
 * REFERENCE
 * ==> link list
 * ==> high order function
*/
static int	check_transform(t_list **result, void *lst, void (*del)(void *))
{
	if (lst == NULL)
	{
		ft_lstclear(result, del);
		return (1);
	}
	return (0);
}

/*
 * FUNCTION (G)
 * ==> apply a function to a node and put it on the result
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 3)
 * ==> 1.t_list * 2. function 3.function
 * WORK
 * ==> traverse every node and apply function from parameter 1 to every node
 * ==> the new node will have a new address
 * ==> clear the old link list
 * RETURN
 * ==> address new link list
 * REFERENCE
 * ==> link list
 * ==> high order function
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*result;
	void	*apply_func;

	if (!f || !del || !lst)
		return (NULL);
	result = NULL;
	while (lst != NULL)
	{
		apply_func = f(lst->content);
		if (check_transform(&result, apply_func, del))
			return (NULL);
		new_node = ft_lstnew(apply_func);
		if (new_node == NULL)
		{
			del(apply_func);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new_node);
		lst = lst->next;
	}
	return (result);
}
