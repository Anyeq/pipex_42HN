/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:00:01 by asando            #+#    #+#             */
/*   Updated: 2025/09/16 14:01:36 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_p(char **argv, int *fd, char **envp)
{
	int	infile_fd;
	int	res;

	res = 0;
	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		res = -1;
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		res = -1;
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		res = -1;
	if (infile_fd != -1)
		close(infile_fd);
	close_single_pipe(fd);
	if (res == 0 && execute_program(argv[2], envp) != 0)
		res = -2;
	if (res == -1)
		err_exit("pipex: No such file or directory\n");
	else if (res == -2)
		err_exit("pipex: command not found: \n");
	return ;
}

static void	parent_p(char **argv, int *fd, char **envp)
{
	int	outfile_fd;
	int	res;

	res = 0;
	outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
		res = -1;
	if (dup2(fd[0], STDIN_FILENO) == -1)
		res = -1;
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		res = -1;
	if (outfile_fd != -1)
		close(outfile_fd);
	close_single_pipe(fd);
	if (res == 0 && execute_program(argv[3], envp) != 0)
		res = -2;
	if (res == -1)
		err_exit(NULL);
	else if (res == -2)
		err_exit("pipex: command not found: \n");
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	p_id;

	if (argc != 5)
	{
		bad_usage(0);
		return (1);
	}
	if (pipe(fd) == -1)
		err_exit(NULL);
	p_id = fork();
	if (p_id == -1)
	{
		close_single_pipe(fd);
		err_exit(NULL);
	}
	if (p_id == 0)
		child_p(argv, fd, envp);
	else
	{
		waitpid(p_id, NULL, 0);
		parent_p(argv, fd, envp);
	}
	return (0);
}
