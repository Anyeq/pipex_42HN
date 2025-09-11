/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:53:05 by asando            #+#    #+#             */
/*   Updated: 2025/09/11 15:56:18 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	create_child_p(char **argv, int **fds, int n_pipes, char **envp)
{
	int	i;
	int	p_id;

	i = -1;
	p_id = -1;
	while (++i <= n_pipes)
	{
		p_id = fork();
		if (p_id == -1)
		{
			close_fds(fds);
			err_exit();
		}
		else if (p_id == 0)
			break ;
	}
	if (p_id != 0)
		close_fds(fds);
	if (p_id == 0)
	{
		child_p(argv, fds, n_pipes, i);
		if (execute_program(argv[i + 2], envp) == -1)
			err_exit();
	}
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	int	**fds;
	int	n_pipes;

	n_pipes = argc - 4;
	if (argc >= 5)
	{
		fds = init_fds(n_pipes);
		if (fds == NULL || init_pipes(fds) == -1)
			err_exit();
		create_child_p(argv, fds, n_pipes, envp);
		wait_all_child_p(n_pipes);
	}
	return (0);
}
