/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:21:15 by asando            #+#    #+#             */
/*   Updated: 2025/09/12 11:32:23 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	first_child_process(char **argv, int **fds)
{
	int	file_fd;

	file_fd = 0;
	file_fd = open_file(argv[1], OF_RD);
	if (file_fd == -1)
		return (-1);
	if (dup2(file_fd, STDIN_FILENO) == -1)
		return (-1);
	if (dup2(fds[0][1], STDOUT_FILENO) == -1)
		return (-1);
	close(file_fd);
	return (0);
}

static int	last_child_process(char **argv, int **fds, int i)
{
	int	file_fd;
	int	len_argv;

	len_argv = 0;
	while (argv[len_argv])
		len_argv++;
	file_fd = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		file_fd = open_file(argv[len_argv - 1], OF_APP);
	else
	{
		file_fd = open_file(argv[len_argv - 1], OF_TR);
		i -= 1;
	}
	if (file_fd == -1)
		return (-1);
	if (dup2(fds[i][0], STDIN_FILENO) == -1)
		return (-1);
	if (dup2(file_fd, STDOUT_FILENO) == -1)
		return (-1);
	close(file_fd);
	return (0);
}

static int	middle_child_process(int **fds, int i)
{
	if (dup2(fds[i - 1][0], STDIN_FILENO) == -1)
		return (-1);
	if (dup2(fds[i][1], STDOUT_FILENO) == -1)
		return (-1);
	return (0);
}

void	wait_all_child_p(int n_pipes)
{
	int	i;

	i = 0;
	while (i <= n_pipes)
	{
		wait(NULL);
		i++;
	}
	return ;
}

void	child_p(char **argv, int **fds, int n_pipes, int i)
{
	int	res;

	res = 0;
	if (i == 0)
	{
		if (first_child_process(argv, fds) == -1)
			res = -1;
	}
	else if (i == n_pipes)
	{
		if (last_child_process(argv, fds, i) == -1)
			res = -1;
	}
	else if (i > 0 && i < n_pipes)
	{
		if (middle_child_process(fds, i) == -1)
			res = -1;
	}
	if (res == -1)
	{
		close_fds(fds);
		err_exit(NULL);
	}
	close_fds(fds);
	return ;
}
