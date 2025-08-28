/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:52:45 by asando            #+#    #+#             */
/*   Updated: 2025/03/19 13:20:02 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (G)
 * ==> Count item connected with linklist structure
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 1)
 * ==> 1.t_list *
 * WORK
 * ==> traverse linklist by accessing next item inside linklist structure
 * ==> stop traveersing after it reach the last item
 * RETURN
 * ==> number of item connected by linklist structure
 * REFERENCE
 * ==> link list data structure
*/
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		count++;
	}
	count++;
	return (count);
}
