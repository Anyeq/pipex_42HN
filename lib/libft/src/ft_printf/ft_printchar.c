/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:36:47 by asando            #+#    #+#             */
/*   Updated: 2025/07/15 17:10:42 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char chr, t_prse *prse)
{
	if (write(STDOUT_FILENO, &chr, 1) < 1)
	{
		prse->write_err = 1;
		return (0);
	}
	return (1);
}
