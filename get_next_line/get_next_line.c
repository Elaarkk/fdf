/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:50:31 by acolonne          #+#    #+#             */
/*   Updated: 2025/02/03 19:01:52 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*build_line(char *buf)
{
	int			i;
	int			j;
	char		*line;

	i = 0;
	j = 0;
	if (!buf[i])
		return (0);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	while (j < i + 1)
	{
		line[j] = buf[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*buffer_remainder(char *buf)
{
	int		i;
	int		j;
	char	*buf_remainder;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	buf_remainder = malloc(ft_strlen(buf) - i + 1);
	if (!buf_remainder)
		return (NULL);
	i++;
	while (buf[i])
		buf_remainder[j++] = buf[i++];
	buf_remainder[j] = '\0';
	free(buf);
	return (buf_remainder);
}

char	*read_file(char *buf, int fd)
{
	char		*line;
	int			nbytes;

	nbytes = 1;
	line = malloc(BUFFER_SIZE + 1);
	if (!line)
		return (0);
	ft_bzero(line, BUFFER_SIZE + 1);
	while (nbytes > 0 && !(ft_strchr(line, '\n')))
	{
		nbytes = read(fd, line, BUFFER_SIZE);
		if (nbytes < 0)
		{
			free (line);
			free(buf);
			return (NULL);
		}
		line[nbytes] = '\0';
		buf = ft_strjoin(buf, line);
	}
	free(line);
	return (buf);
}

char	*get_next_line(int fd, int ext)
{
	static char	*buf;
	char		*line;

	if (ext == 1)
	{
		if (buf)
			free(buf);
		return (0);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		ft_bzero(buf, BUFFER_SIZE + 1);
	}
	buf = read_file(buf, fd);
	if (!buf)
		return (NULL);
	line = build_line(buf);
	buf = buffer_remainder(buf);
	return (line);
}
