/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:59:10 by asando            #+#    #+#             */
/*   Updated: 2025/09/05 08:47:35 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_program(char *cmd, char *argv, char **envp)
{
	char *res;
	char **paths;

	res = NULL;
	while (envp != NULL && ft_strncmp(*envp, "PATH", 4) != 0)
		envp++;
	paths = ft_split((*envp) + 5, ':');
	while (paths != NULL)
	{
		res = ft_strjoin(*paths, cmd);
		if (access(res, F_OK) == 0)
			break;
		free(res);
		res == NULL;
		paths++;
	}
	if (paths == NULL)
	return (res);
}

void	execute_program()
{
	return ;
}

void	err_exit(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

//take the input "cmd option option"
//take the cmd as a address to look on PATH
//take the option for excecuting the cmd

char **grab_arg(char *argv)
{
	char **result;
	result = ft_split(argv, ' ');

}

