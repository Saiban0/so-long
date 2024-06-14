/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:05:17 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/14 21:42:05 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(char	*path, t_so_long *game)
{
	if (ft_strncmp(path + (ft_strlen(path) - 4), ".ber", 4) != 0)
		safe_exit("The map is not in .ber", game);
}

int	check_length(char	*line, size_t width)
{
	if (!ft_strchr(line, '\n') && ft_strlen(line) == width)
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

int	check_characters(t_so_long	*game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		if (i != game->map_height - 1)
			game->map[i][game->map_width] = 0;
		j = 0;
		while (game->map[i][j])
		{
			if (ft_strchr("10PCE\n", game->map[i][j]) == NULL)
				return (1);
			if (game->map[i][j] == 'P')
			{
				game->player_coords.x = i;
				game->player_coords.y = j;
				game->player_coords.z = 10;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_surrounded(t_so_long	*game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		if (i == 0 || i == game->map_height - 1)
		{
			j = 0;
			while (game->map[i][j])
			{
				if (game->map[i][j] != '1')
					return (1);
				j++;
			}
		}
		else
		{
			if (game->map[i][0] != '1' ||
				game->map[i][game->map_width - 1] != '1')
				return (1);
		}
		i++;
	}
	return (0);
}
