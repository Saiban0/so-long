/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:25:02 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/17 18:29:56 by bchedru          ###   ########.fr       */
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
	if (game->map[new_x][new_y] == '1' || (game->map[new_x][new_y] == 'E'
				&& game->collected_all != 1))
		return (0);
	if (game->map[new_x][new_y] == 'M')
	{
		game->player_health--;
		ft_printf("You got damaged, new health = %d\n", game->player_health);
		return (0);
	}
	return (1);
}

void	player_move_up(t_so_long *game)
{
	if (is_valid_move(game, -1, 0) == 1)
	{
		game->player_coords.x -= 1;
		if(game->map[game->player_coords.x][game->player_coords.y] == 'E')
			safe_exit("You won!", game);
		game->player_image->instances->y -= SO_LONG_UNIT;
		game->movement_count++;
		ft_printf("Movements = %d\n", game->movement_count);
	}
}

void	player_move_down(t_so_long *game)
{
	if (is_valid_move(game, 1, 0) == 1)
	{
		game->player_coords.x += 1;
		if(game->map[game->player_coords.x][game->player_coords.y] == 'E')
			safe_exit("You won!", game);
		game->player_image->instances->y += SO_LONG_UNIT;
		game->movement_count++;
		ft_printf("Movements = %d\n", game->movement_count);
	}
}

void	player_move_left(t_so_long *game)
{
	if (is_valid_move(game, 0, -1) == 1)
	{
		game->player_coords.y -= 1;
		if(game->map[game->player_coords.x][game->player_coords.y] == 'E')
			safe_exit("You won!", game);
		game->player_image->instances->x -= SO_LONG_UNIT;
		game->movement_count++;
		ft_printf("Movements = %d\n", game->movement_count);
	}
}

void	player_move_right(t_so_long *game)
{
	if (is_valid_move(game, 0, 1) == 1)
	{
		game->player_coords.y += 1;
		if(game->map[game->player_coords.x][game->player_coords.y] == 'E')
			safe_exit("You won!", game);
		game->player_image->instances->x += SO_LONG_UNIT;
		game->movement_count++;
		ft_printf("Movements = %d\n", game->movement_count);
	}
}
