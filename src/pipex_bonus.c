/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:53:05 by asando            #+#    #+#             */
/*   Updated: 2025/09/09 14:52:57 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	child_p(char **argv, int **fds, char **envp, int i)
{
	int	j;
	int	file_fd;
	int	len_argv;
	j = 0;

	file_fd = 0;
	len_argv = 0;
	while (argv[len_argv])
		len_argv++;
	if (i == 0)
	{
		file_fd = open_file(argv[1], OF_RD);
		if (file_fd == -1)
		{
			close_fds(fds);
			err_exit();
		}
		dup2(file_fd, STDIN_FILENO);
		dup2(fds[i][1], STDOUT_FILENO);
	}
	else if (i == n_pipes)
	{
		file_fd = open_file(argv[len_argv - 1], OF_TR);
		if file_fd == -1)
		{
			close_fds(fds);
			err_exit();
		}
		dup2(fds[i][0], STDIN_FILENO);
		dup2(file_fd, STDOUT_FILENO);
	}
	else
	{
		dup2(fds[i][0], STDIN_FILENO);
		dup2(fds[i][1], STDOUT_FILENO);
	}
	return ;
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
		while (i < n_pipes)
		{
			p_id = fork();
			if (p_id == -1)
			{
				close_fds(fds);
				err_exit();
			}
			else if (p_id == 0)
				break;
			i++;
		}
		if (p_id == 0)
		{
			child_p(argv, fds, n_pipes, i);
			execute_program(argv[i], envp);
		}
		else
		{
			waitpid(p_id, NULL, 0);
			parent_p(argv, fds, envp, i);
		}
	}
	return (0);
}
