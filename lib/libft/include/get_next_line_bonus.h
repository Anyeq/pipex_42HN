/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:41:04 by asando            #+#    #+#             */
/*   Updated: 2025/09/11 18:19:27 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char	*get_next_line(int fd);
ssize_t	read_fd(int fd, char *buff, char **storage);
int		err_check(int fd, char **storage);
char	*ft_find_line(char **storage, ssize_t byte_read);
char	*ft_clean_storage(char *storage, char **line);
char	*ft_store_char(char *storage, char *buff, int *new_line_found);
#endif
