/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:59:10 by asando            #+#    #+#             */
/*   Updated: 2025/09/09 17:47:36 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_program(char *cmd, char **envp)
{
	char	*res;
	char	**paths;
	int		i;

	i = 0;
	res = NULL;
	while (envp && *envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (envp == NULL || *envp == NULL)
		return (res);
	paths = ft_split((*envp) + 5, ':');
	while (paths[i])
	{
		res = ft_strjoin(paths[i++], cmd);
		if (access(res, F_OK) == 0)
			break ;
		free(res);
		res = NULL;
	}
	i = 0;
	while (paths && paths[i])
		free(paths[i++]);
	free(paths);
	return (res);
}

void	execute_program(char *argv, char **envp)
{
	char	*path;
	char	*slash_command;
	char	**command;
	int		i;

	i = 0;
	command = ft_split(argv, ' ');
	if (command == NULL)
		return ;
	slash_command = ft_strjoin("/", command[0]);
	if (slash_command == NULL)
		return ;
	path = find_program(slash_command, envp);
	free(slash_command);
	if (path == NULL || execve(path, command, envp) == -1)
	{
		while (command[i])
			free(command[i++]);
		free(command);
		err_exit();
	}
	return ;
}

void	err_exit(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}
