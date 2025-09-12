/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:50:01 by asando            #+#    #+#             */
/*   Updated: 2025/09/11 22:19:21 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	**init_fds(int npipe)
{
	int	**fds;
	int	i;
	int	j;

	i = 0;
	j = 0;
	fds = malloc(sizeof(int *) * (npipe + 1));
	if (fds == NULL)
		return (NULL);
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

void	close_fds(int **fds)
{
	int	i;

	i = 0;
	while (fds[i])
	{
		close(fds[i][0]);
		close(fds[i][1]);
		free(fds[i++]);
	}
	free(fds[i]);
	free(fds);
	return ;
}

int	init_pipes(int **fds)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (fds[i])
	{
		if (pipe(fds[i]) == -1)
		{
			while (j < i)
			{
				close(fds[j][0]);
				close(fds[j][1]);
				free(fds[j++]);
			}
			while (fds[i])
				free(fds[i++]);
			free(fds[i]);
			free(fds);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	open_file(char *argv, t_offlag of_flag)
{
	int	file_fd;

	file_fd = 0;
	if (of_flag & OF_APP)
		file_fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (of_flag & OF_TR)
		file_fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (of_flag & OF_RD)
		file_fd = open(argv, O_RDONLY, 0644);
	return (file_fd);
}
