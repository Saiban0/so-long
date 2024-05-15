/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:18:45 by bchedru           #+#    #+#             */
/*   Updated: 2024/04/11 18:42:16 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1] = {"\0"};
	char		*line;

	line = ft_calloc(1, 1);
	if (!line)
		return (NULL);
	if ((fd < 0 && fd > MAX_FD) || BUFFER_SIZE <= 0)
		return (free(line), NULL);
	if (buffer[fd][0] != '\0')
	{
		line = ft_strjoin(line, buffer[fd]);
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
		line = ft_strjoin(line, buffer);
		if (!line)
			return (free(line), NULL);
	}
	if (ft_find_n(line) > -1)
		line[ft_find_n(line) + 1] = '\0';
	if (line[0] == '\0')
		return (free(line), NULL);
	return (line);
}
// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	int	fd;
// 	char *line = NULL;
// 	int i = 0;
// 	(void)argc;
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	while (i < 15)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }