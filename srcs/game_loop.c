/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:11:31 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/18 16:56:48 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_loop(t_so_long *game)
{
	collectible_collision(game);
	if (game->collectibles == game->max_collectibles)
		game->collected_all = 1;
	if (game->player_health < 1)
		safe_exit("YOU DIED\n", game);
	if (game->ticks % 60 == 0)
		move_monsters(game, game->monster_array);
	game->ticks++;
}

void	collectible_collision(t_so_long *game)
{
	t_coord	temp;

	if (game->map[game->player_coords.x][game->player_coords.y] == 'C')
	{
		temp.x = game->player_coords.x;
		temp.y = game->player_coords.y;
		temp.z = 6;
		load_image(game->mlx_ptr, temp, game->floor_image, 1);
		game->collectibles++;
	}
}
