/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:53:05 by asando            #+#    #+#             */
/*   Updated: 2025/09/16 13:57:27 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	multiple_fork(int **fds, int n_pipes, int *p_id)
{
	int	i;

	i = 0;
	while (i <= n_pipes)
	{
		*p_id = fork();
		if (*p_id == -1)
		{
			close_fds(fds);
			err_exit(NULL);
		}
		else if (*p_id == 0)
			return (i);
		i++;
	}
	close_fds(fds);
	wait_all_child_p(n_pipes);
	return (0);
}

static void	create_child_p(char **argv, int **fds, int n_pipes, char **envp)
{
	int	i;
	int	p_id;

	p_id = -1;
	i = multiple_fork(fds, n_pipes, &p_id);
	if (p_id == 0)
	{
		child_p(argv, fds, n_pipes, i);
		if (execute_program(argv[i + 2], envp) != 0)
			err_exit("pipex: command not found: \n");
	}
	return ;
}

static void	here_doc_scan(char **argv, int **fds)
{
	char	*input_str;
	int		limiter_len;

	limiter_len = ft_strlen(argv[2]);
	input_str = NULL;
	while (1)
	{
		input_str = get_next_line(0);
		if (!input_str)
			err_exit(NULL);
		if (ft_strncmp(input_str, argv[2], limiter_len) == 0
			&& input_str[limiter_len] == '\n')
		{
			free(input_str);
			close_fds(fds);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(input_str, fds[0][1]);
		free(input_str);
	}
	return ;
}

static void	here_doc_exec(char **argv, int **fds, int n_pipes, char **envp)
{
	int	i;
	int	p_id;

	i = multiple_fork(fds, n_pipes, &p_id);
	if (p_id == 0)
	{
		if (i == n_pipes)
			here_doc_scan(argv, fds);
		else if (i < n_pipes - 1)
			child_p(argv, fds, n_pipes, i + 1);
		else if (i == n_pipes - 1)
			child_p(argv, fds, n_pipes - 1, i);
		if (i != n_pipes && execute_program(argv[i + 3], envp) != 0)
			err_exit("pipex: command not found: \n");
	}
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	int	**fds;
	int	n_pipes;
	int	here_doc_mode;

	n_pipes = argc - 4;
	fds = NULL;
	here_doc_mode = 0;
	if (argc < 5)
		return (bad_usage(0));
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argv[1][8] == '\0')
	{
		if (argc < 6)
			return (bad_usage(1));
		here_doc_mode = 1;
	}
	fds = init_fds(n_pipes);
	if (fds == NULL || init_pipes(fds) == -1)
		err_exit(NULL);
	if (here_doc_mode)
		here_doc_exec(argv, fds, n_pipes, envp);
	else
		create_child_p(argv, fds, n_pipes, envp);
	return (0);
}
