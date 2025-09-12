/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:59:10 by asando            #+#    #+#             */
/*   Updated: 2025/09/12 11:24:14 by asando           ###   ########.fr       */
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

int	execute_program(char *argv, char **envp)
{
	char	*path;
	char	*slash_command;
	char	**command;
	int		i;

	i = 0;
	command = ft_split(argv, ' ');
	if (command == NULL)
		return (-1);
	slash_command = ft_strjoin("/", command[0]);
	if (slash_command == NULL)
		return (-1);
	path = find_program(slash_command, envp);
	free(slash_command);
	if (path == NULL || execve(path, command, envp) == -1)
	{
		while (command[i])
			free(command[i++]);
		free(command);
		if (path == NULL)
			return (-2);
		return (-1);
	}
	return (0);
}

void	err_exit(char *msg)
{
	if (msg == NULL)
		perror("pipex");
	else
		ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	close_single_pipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	return ;
}

int	bad_usage(int bonus_mode)
{
	char	*str;

	str = "./pipex \"here_doc\" <LIMITER> <cmd> <cmd1> <...> <outfile>\n";
	if (bonus_mode)
	{
		ft_putstr_fd("pipex: Bad argument\n", 2);
		ft_putstr_fd("./pipex <infile> <cmd1> <cmd2> <...> <outfile>\n", 2);
		ft_putstr_fd(str, 2);
		return (-1);
	}
	ft_putstr_fd("pipex: Bad argument\n", 2);
	ft_putstr_fd("./pipex <infile> <cmd1> <cmd2> <outfile>\n", 2);
	return (-1);
}
