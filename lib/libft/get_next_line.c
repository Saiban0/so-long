/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:18:45 by bchedru           #+#    #+#             */
/*   Updated: 2024/05/23 17:21:23 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1] = {"\0"};
	char		*line;

	line = ft_calloc_gnl(1, 1);
	if (!line)
		return (NULL);
	if ((fd < 0 && fd > MAX_FD) || BUFFER_SIZE <= 0)
		return (free(line), NULL);
	if (buffer[fd][0] != '\0')
	{
		line = ft_strjoin_gnl(line, buffer[fd]);
		if (!line)
			return (free(line), NULL);
		if (ft_find_n(line) > -1)
			line[ft_find_n(line) + 1] = '\0';
	}
	line = ft_read2buff(line, buffer[fd], fd);
	if (ft_find_n(buffer[fd]) > -1)
		ft_strcpy(buffer[fd], buffer[fd] + ft_find_n(buffer[fd]) + 1);
	return (line);
}

char	*ft_read2buff(char *line, char *buffer, int fd)
{
	int	bytes_read;

	bytes_read = 1;
	while (ft_find_n(line) == -1 && bytes_read != 0)
	{
		buffer[0] = '\0';
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), NULL);
		buffer[bytes_read] = '\0';
		line = ft_strjoin_gnl(line, buffer);
		if (!line)
			return (free(line), NULL);
	}
	if (ft_find_n(line) > -1)
		line[ft_find_n(line) + 1] = '\0';
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}
