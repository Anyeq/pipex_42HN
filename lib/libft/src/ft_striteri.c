/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:44:19 by asando            #+#    #+#             */
/*   Updated: 2025/03/19 13:51:56 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * FUNCTION (G)
 * ==> applied function f to every character
 * CALLED FUNCTION
 * ==>
 * PARAMETER (n = 2)
 * ==> 1.char const * 2.function that return nothing
 * WORK
 * ==> travesse s and using the function provided in parameter change s
 * RETURN
 * ==> none
 * REFERENCE
 * ==>
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
