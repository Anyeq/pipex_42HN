/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:00:01 by asando            #+#    #+#             */
/*   Updated: 2025/09/04 18:37:13 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pid_child(char **argv, int *fd)
{
	int	infile_fd;

	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
	{

	}
	//open the file that is given
	//check if the file is existed
}
void	pid_parent(){}

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
	pipe(fd);
	p_id = fork();
	if (p_id == 0)
	{
		// take the file1
		// execute the cmd1
		// send the result into parent
	}
	else
	{
		//take the result
		//execute cmd2
		//
	}
	//take the input
	//check the file1 and file2 if existed
	return (0);
}
