/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:53:05 by asando            #+#    #+#             */
/*   Updated: 2025/09/08 17:25:24 by asando           ###   ########.fr       */
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
	int	n_pipes;
	int	p_id;
	int	i;

	i = 0;
	n_pipes = argc - 4;
	if (argc >= 5)
	{
		if (check_hello_doc(argv[1]) == 0)
			run_hello_doc_function();
		fds = init_fds(n_pipes);
		if (fds == NULL || init_pipes(pipes) == -1)
			err_exit();
		// for non hello_doc case
		while (i < n_pipes)
		{
			p_id = fork();
			if (p_id == -1)
				err_exit();
			else if (p_id == 0)
				break;
			i++;
		}
		if (p_id == 0)
			child_p(argv, fds, envp, i);
		else
		{
			waitpid(p_id, NULL, 0);
			parent_p(argv, fds, envp, i);
		}
	}
	return (0);
}
