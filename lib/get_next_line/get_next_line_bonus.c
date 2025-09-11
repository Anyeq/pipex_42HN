/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 09:40:51 by asando            #+#    #+#             */
/*   Updated: 2025/05/19 09:00:20 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_store_char(char *storage, char *buff, int *new_line_found)
{
	char	*result;

	if (!storage)
	{
		storage = malloc(1 * sizeof(char));
		if (!storage)
		{
			free(buff);
			return (NULL);
		}
		storage[0] = '\0';
	}
	result = ft_strjoin(storage, buff);
	if (ft_strchr(buff, '\n'))
		*new_line_found = 1;
	free(buff);
	if (!result)
	{
		free(storage);
		return (NULL);
	}
	free(storage);
	return (result);
}

char	*ft_find_line(char **storage, ssize_t byte_read)
{
	char	*line;
	int		size;
	int		i;

	if (byte_read < 0 || *storage == NULL)
		return (NULL);
	i = 0;
	while ((*storage)[i] != '\n' && (*storage)[i])
		i++;
	if ((*storage)[i] == '\n')
		size = i + 2;
	else
		size = i + 1;
	line = malloc(size * sizeof(char));
	if (!line)
	{
		free(*storage);
		*storage = NULL;
		return (NULL);
	}
	ft_strlcpy(line, *storage, size);
	return (line);
}

char	*ft_clean_storage(char *storage, char **line)
{
	char	*result;
	int		size;
	int		i;

	i = 0;
	while (storage[i] != '\n' && storage[i])
		i++;
	size = ft_strlen(storage) - i;
	if (size < 2)
	{
		free(storage);
		return (NULL);
	}
	result = malloc((size) * sizeof(char));
	if (!result)
	{
		free(*line);
		*line = NULL;
		free(storage);
		return (NULL);
	}
	ft_strlcpy(result, &storage[i + 1], size);
	free(storage);
	return (result);
}

ssize_t	read_fd(int fd, char *buff, char **storage)
{
	ssize_t	byte_read;

	if (!buff)
	{
		free(*storage);
		*storage = NULL;
		return (-1000);
	}
	byte_read = read(fd, buff, BUFFER_SIZE);
	if (byte_read < 0 || byte_read == 0)
	{
		free(buff);
		return (byte_read);
	}
	buff[byte_read] = '\0';
	return (byte_read);
}

char	*get_next_line(int fd)
{
	char		*buff;
	ssize_t		byte_read;
	char		*line;
	static char	*storage[OPEN_MAX];
	int			new_line_found;

	if (!err_check(fd, &storage[fd]))
		return (NULL);
	new_line_found = 0;
	while (!new_line_found)
	{
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		byte_read = read_fd(fd, buff, &storage[fd]);
		if (byte_read <= 0)
			break ;
		storage[fd] = ft_store_char(storage[fd], buff, &new_line_found);
		if (!storage[fd])
			return (NULL);
	}
	line = ft_find_line(&storage[fd], byte_read);
	if (!storage[fd] && !(line))
		return (NULL);
	storage[fd] = ft_clean_storage(storage[fd], &line);
	return (line);
}
