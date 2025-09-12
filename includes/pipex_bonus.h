/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:53:46 by asando            #+#    #+#             */
/*   Updated: 2025/09/11 22:41:59 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "pipex.h"
# include "libft.h"
# include "get_next_line_bonus.h"

typedef enum e_of_flag
{
	OF_RD = 1 << 0,
	OF_TR = 1 << 1,
	OF_APP = 1 << 2
}	t_offlag;

int		**init_fds(int npipe);
void	close_fds(int **fds);
int		init_pipes(int **fds);
int		open_file(char *argv, t_offlag of_flag);
void	wait_all_child_p(int n_pipes);
void	child_p(char **argv, int **fds, int n_pipes, int i);

#endif
