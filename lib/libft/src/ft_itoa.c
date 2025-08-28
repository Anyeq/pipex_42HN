/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:23:29 by asando            #+#    #+#             */
/*   Updated: 2025/03/19 14:29:05 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * FUNCTION (L)
 * ==> reverse string
 * CALLED FUNCTION
 * ==> ft_isdigit(libft)
 * PARAMETER (n = 3)
 * ==> 1. char * 2. char * 3 int
 * WORK
 * ==> take src and reverse it
 * RETURN
 * ==> none
 * REFERENCE
 * ==>
*/
static void	reverse(char *res, char *num, int i)
{
	int	j;
	int	a;

	j = i;
	a = 0;
	if (ft_isdigit(num[0]) == 0)
	{
		res[0] = num[0];
		a = 1;
	}
	while (i > 0)
	{
		res[j - i + a] = num[i - 1];
		i--;
	}
	res[j] = '\0';
}

/*
 * FUNCTION (L)
 * ==> check if num containe negative sign
 * CALLED FUNCTION
 * ==> none
 * PARAMETER (n = 3)
 * ==> 1. int * 2. char * 3. int *
 * WORK
 * ==> check if at index 0 is a sign
 * ==> change the iteration number to 1 if it contain sign
 * RETURN
 * ==> none
 * REFERENCE
 * ==> 
*/
static void	check_num(int *n, char *char_num, int *i)
{
	char_num[0] = '-';
	*i = 1;
	*n = *n * -1;
}

/*
 * FUNCTION (l)
 * ==> solving case if parameter is INT_MIN
 * CALLED FUNCTION
 * ==> malloc(stdlib)
 * PARAMETER (n = 0)
 * ==> none 
 * WORK
 * ==> allocate enough memory and copy INT_MIN value into it
 * RETURN
 * ==> address of char * or NULL
 * REFERENCE
 * ==>
*/
static char	*int_mincase(void)
{
	char	*res;

	res = malloc(12 * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, "-2147483648", 12);
	return (res);
}

/*
 * FUNCTION (G)
 * ==> convert int to string (ex: 123 to "123") 
 * CALLED FUNCTION
 * ==> ft_isdigit(libft), malloc(stdlib)i, reverse(l), check_num(l)
 * PARAMETER (n = 1)
 * ==> 1. int (ex = 123)
 * WORK
 * ==> take parameter and convert it to string by finding value divided by 10
 * ==> value than store in a string variable
 * ==> string variable than reversed to get the right order of string
 * RETURN
 * ==> string
 * REFERENCE
 * ==>
*/
char	*ft_itoa(int n)
{
	char	*num_string;
	char	char_num[12];
	int		i;

	i = 0;
	if (n == INT_MIN)
		return (int_mincase());
	if (n == 0)
		char_num[i++] = '0';
	if (n < 0)
		check_num(&n, char_num, &i);
	while (n > 0)
	{
		char_num[i] = (n % 10) + '0';
		i++;
		n = n / 10;
	}
	char_num[i] = '\0';
	num_string = malloc((i + 1) * sizeof(char));
	if (num_string == NULL)
		return (NULL);
	reverse(num_string, char_num, i);
	return (num_string);
}
