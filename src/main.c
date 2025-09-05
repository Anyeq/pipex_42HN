/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:00:01 by asando            #+#    #+#             */
/*   Updated: 2025/09/05 12:09:19 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_p(char **argv, int *fd, char **envp)
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
	execute_program(argv[2], envp);
	return ;
}

static void	parent_p(char **argv, int *fd, char **envp)
{
	int	outfile_fd;

	outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile_fd == -1)
		err_exit();
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		err_exit();
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		err_exit();
	execute_program(argv[3], envp);
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	p_id;

	if (argc != 5)
	{
		ft_putstr_fd("Error argument not 4\n", 2);
		ft_putstr_fd("Format: ./pipex <file1> <cmd1> <cmd2> <file2>", 1);
		return (1);
	}
	if (pipe(fd) == -1)
		err_exit();
	p_id = fork();
	if (p_id == -1)
		err_exit();
	if (p_id == 0)
		child_p(argv, fd, envp);
	else
		parent_p(argv, fd, envp);
	return (0);
}
