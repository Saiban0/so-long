/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:25:02 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/20 22:31:27 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	is_valid_move(t_so_long *game, int mvt_x, int mvt_y)
{
	t_coord	new_coords;
	bool	square_monster;

	new_coords.y = game->player_coords.y + mvt_y;
	new_coords.x = game->player_coords.x + mvt_x;
	square_monster = 0;
	if (!(new_coords.x >= 1 && new_coords.x < game->map_height - 1)
		|| !(new_coords.y >= 1 && new_coords.y < game->map_width - 1))
		return (0);
	if (game->map[new_coords.x][new_coords.y] == '1')
		return (0);
	if (game->map[new_coords.x][new_coords.y] == 'M')
	{
		square_monster = (&game->monster_image.square
				->instances[get_monster_id(game, new_coords)])->enabled;
		if (square_monster)
		{
			game->player_health--;
			kill_monster(game, new_coords);
			display_lives(game);
			return (0);
		}
	}
	return (1);
}

void	player_move_up(t_so_long *game)
{
	if (is_valid_move(game, -1, 0) == 1)
	{
		game->player_coords.x -= 1;
		if (game->map[game->player_coords.x][game->player_coords.y] == 'E'
				&& game->collected_all == 1)
			safe_exit("You won!\n", game);
		game->player_image->instances->y -= SO_LONG_UNIT;
		game->movement_count++;
		display_movement(game);
	}
}

void	player_move_down(t_so_long *game)
{
	if (is_valid_move(game, 1, 0) == 1)
	{
		game->player_coords.x += 1;
		if (game->map[game->player_coords.x][game->player_coords.y] == 'E'
				&& game->collected_all == 1)
			safe_exit("You won!\n", game);
		game->player_image->instances->y += SO_LONG_UNIT;
		game->movement_count++;
		display_movement(game);
	}
}

void	player_move_left(t_so_long *game)
{
	if (is_valid_move(game, 0, -1) == 1)
	{
		game->player_coords.y -= 1;
		if (game->map[game->player_coords.x][game->player_coords.y] == 'E'
				&& game->collected_all == 1)
			safe_exit("You won!\n", game);
		game->player_image->instances->x -= SO_LONG_UNIT;
		game->movement_count++;
		display_movement(game);
	}
}

void	player_move_right(t_so_long *game)
{
	if (is_valid_move(game, 0, 1) == 1)
	{
		game->player_coords.y += 1;
		if (game->map[game->player_coords.x][game->player_coords.y] == 'E'
				&& game->collected_all == 1)
			safe_exit("You won!\n", game);
		game->player_image->instances->x += SO_LONG_UNIT;
		game->movement_count++;
		display_movement(game);
	}
}
