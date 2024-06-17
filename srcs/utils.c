/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:09:20 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/17 19:57:16 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			ft_printf("%c", game->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n\n");
}

void	open_file(t_so_long *game, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (!fd)
		safe_exit("File not found.", game);
	if (parse(0, game, fd) == -1)
		safe_exit("Map is not rectangular", game);
	if (game->map_height < 4 && game->map_width < 4)
		safe_exit("Map is too small.", game);
	if (check_characters(game) == 1)
		safe_exit("Characters in map not defined", game);
	if (check_surrounded(game) == 1)
		safe_exit("Map is not entirely surrounded by walls", game);
	if (check_special_character_occurences(game))
		safe_exit("Map must have only one player and one exit", game);
}

static void	initialize_map_variables(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_coords.x = i;
				game->player_coords.y = j;
				game->player_coords.z = 10;
			}
			if (game->map[i][j] == 'C')
				game->max_collectibles++;
			if (game->map[i][j] == 'M')
				game->max_monsters++;
			j++;
		}
		i++;
	}
}

void	initialize_starting_variables(t_so_long *game)
{
	game->max_collectibles = 0;
	game->player_health = PLAYER_HEALTH;
	game->ticks = 0;
	game->max_monsters = 0;
	initialize_map_variables(game);
}

void	update_map(t_so_long *game, t_coord coords)
{
	if (game->map[coords.x][coords.y] == '1')
	{
		coords.z = 5;
		load_image(game->mlx_ptr, coords, game->wall_image, 1);
	}
	if (game->map[coords.x][coords.y] == '0')
	{
		coords.z = 0;
		load_image(game->mlx_ptr, coords, game->floor_image, 1);
	}
	else
		image_placement_bis(game, coords);
}
