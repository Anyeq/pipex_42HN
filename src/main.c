/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:00:01 by asando            #+#    #+#             */
/*   Updated: 2025/09/05 07:29:14 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_p(char **argv, int *fd, char **envp)
{
	int	infile_fd;

	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		err_exit();
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		err_exit();
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		err_exit();
	return ;
}

void	parent_p(char **argv, int fd, char **envp)
{
	int	outfile_fd;

	outfile_fd = open(argv[5], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile_fd == -1)
		err_exit();
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		err_exit();
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		err_exit();
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	// non bonus project
	// argc min 5
	// bonus argc > 5
	// learn how to support here_doc
	// ./pipex infile "ls -l" "wc -l" outfile example case
	int		fd[2];
	pid_t	p_id;

	if (argc != 5)
	{
		ft_putstr_fd("Error argument not 4", 2);
		ft_putstr_fd("Format: ./pipex <file1> <cmd1> <cmd2> <file2>");
		return (1);
	}
	if (pipe(fd) == -1)
		err_exit();
	p_id = fork();
	if (p_id == -1)
		err_exit();
	if (p_id == 0)
		child_p(argv, &fd, envp);
	parent_p(argv, &fd, envp);
	return (0);
}
