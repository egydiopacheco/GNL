/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epacheco <epacheco@student.42sp.org.       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:42:39 by epacheco          #+#    #+#             */
/*   Updated: 2021/10/12 02:25:48 by epacheco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	read_from_fd(int fd, char **buf, char **auxbuf, char **line);
static void	get_line(char **buf, char **line);

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*auxbuf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	auxbuf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!auxbuf)
		return (NULL);
	if (read(fd, auxbuf, 0) < 0)
	{
		free(auxbuf);
		return (NULL);
	}
	read_from_fd(fd, &buf, &auxbuf, &line);
	if (!line)
		return (NULL);
	return (line);
}

void	read_from_fd(int fd, char **buf, char **auxbuf, char **line)
{
	char	*bufholder;
	ssize_t	size;

	size = 1;
	if (!*buf)
		*buf = ft_strdup("");
	while (size && !ft_strchr(*buf, NEW_LINE))
	{
		size = read(fd, *auxbuf, BUFFER_SIZE);
		*(*auxbuf + size) = NULL_BYTE;
		bufholder = *buf;
		*buf = ft_strjoin(bufholder, *auxbuf);
		free(bufholder);
	}
	free(*auxbuf);
	*auxbuf = NULL;
	get_line(buf, line);
	if (**line == NULL_BYTE)
	{
		free(*line);
		*line = NULL;
	}
}

void	get_line(char **buf, char **line)
{
	char	*bufholder;
	int		j;

	j = 0;
	while (*(*buf + j) != NEW_LINE && *(*buf + j))
		j++;
	if (*(*buf + j++) == NEW_LINE)
	{
		bufholder = *buf;
		*line = ft_substr(bufholder, 0, j);
		*buf = ft_strdup(bufholder + j);
		free(bufholder);
	}
	else
	{
		*line = ft_strdup(*buf);
		free(*buf);
		*buf = 0;
	}
}
