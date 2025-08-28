/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:17:06 by asando            #+#    #+#             */
/*   Updated: 2025/03/19 13:22:49 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> find the last item in linklist structure
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 1)
 * ==> 1.t_list *
 * WORK
 * ==> traverse linklist to go to the last linklist
 * ==> stop traveersing after it reach the last item
 * RETURN
 * ==> address of the last link list
 * REFERENCE
 * ==> link list data structure
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
