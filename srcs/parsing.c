/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:05:17 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/11 12:59:45 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_path(char	*path, t_so_long *game)
{
	if (ft_strncmp(path + (ft_strlen(path) - 4), ".ber", 4) != 0)
		safe_exit("The map is not in .ber", game);
}

void	open_file(t_so_long *game, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (!fd)
		safe_exit("File not found.", game);
	if (parse(0, game, fd) == -1)
		safe_exit("Map is not rectangular", game);
	if (game->map_height < 3 && game->map_width < 3)
		safe_exit("Map is too small.", game);
}

int	check_length(char	*line, size_t width)
{
	if (!ft_strchr(line, '\n') && ft_strlen(line) - 1 == width)
		return (1);
	else if (ft_strlen(line) - 1 == width)
		return (1);
	return (0);
}

int	parse(int depth, t_so_long *game, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
	{
		game->map = ft_calloc(depth + 1, sizeof(char *));
		game->map[depth] = NULL;
		game->map_height = depth;
		return (0);
	}
	if (depth == 0)
		game->map_width = ft_strlen(line) - 1;
	else if (!check_length(line, game->map_width))
		return (free(line), -1);
	if (parse(depth + 1, game, fd) == -1)
		return (free(line), -1);
	game->map[depth] = line;
	return (1);
}
