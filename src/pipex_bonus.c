/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:53:05 by asando            #+#    #+#             */
/*   Updated: 2025/09/08 16:44:22 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

//control if npipe is 0
static int	**init_fd(int npipe)
{
	int	**fds;
	int	i;
	int	j;

	i = 0;
	j = 0;
	fds = malloc(sizeof(int *) * (npipe + 1));
	if (fds == NULL)
		err_exit();
	while (i < npipe)
	{
		fds[i] = malloc(sizeof(int) * 2);
		if (fds[i] == NULL)
			break ;
		i++;
	}
	if (i == npipe)
	{
		fds[i] = NULL;
		return (fds);
	}
	while (j < i)
		free(fds[j++]);
	free(fds);
	return (NULL);
}

static int	init_pipes(int **fds)
{
	int	i;

	i = 0;
	while (fds[i])
	{
		if (pipe[fds[i]] == -1)
		{
			i = 0;
			while (fds[i])
				free(fds[i++]);
			free(fds);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	**fds;
	fds = init_fds(n_pipes);
	if (init_pipes(pipes) == -1)
		err_exit();
	return (0);
}
