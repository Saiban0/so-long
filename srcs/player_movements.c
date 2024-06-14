/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:25:02 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/14 21:42:27 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	is_valid_move(t_so_long *game, int mvt_x, int mvt_y)
{
	int	new_x;
	int	new_y;

	new_x = game->player_coords.x + mvt_x;
	new_y = game->player_coords.y + mvt_y;
	if (!(new_x >= 1 && new_x < game->map_height - 1)
		|| !(new_y >= 1 && new_y < game->map_width - 1))
		return (0);
	if (game->map[new_x][new_y] == '1' || game->map[new_x][new_y] == 'E')
		return (0);
	return (1);
}

void	player_move_up(t_so_long *game)
{
	if (is_valid_move(game, -1, 0) == 1)
	{
		game->map[game->player_coords.x][game->player_coords.y] = '0';
		game->player_coords.x -= 1;
		game->map[game->player_coords.x][game->player_coords.y] = 'P';
		game->player_image->instances->y -= SO_LONG_UNIT;
	}
}

void	player_move_down(t_so_long *game)
{
	if (is_valid_move(game, 1, 0) == 1)
	{
		game->map[game->player_coords.x][game->player_coords.y] = '0';
		game->player_coords.x += 1;
		game->map[game->player_coords.x][game->player_coords.y] = 'P';
		game->player_image->instances->y += SO_LONG_UNIT;
	}
}

void	player_move_left(t_so_long *game)
{
	if (is_valid_move(game, 0, -1) == 1)
	{
		game->map[game->player_coords.x][game->player_coords.y] = '0';
		game->player_coords.y -= 1;
		game->map[game->player_coords.x][game->player_coords.y] = 'P';
		game->player_image->instances->x -= SO_LONG_UNIT;
	}
}

void	player_move_right(t_so_long *game)
{
	if (is_valid_move(game, 0, 1) == 1)
	{
		game->map[game->player_coords.x][game->player_coords.y] = '0';
		game->player_coords.y += 1;
		game->map[game->player_coords.x][game->player_coords.y] = 'P';
		game->player_image->instances->x += SO_LONG_UNIT;
	}
}
