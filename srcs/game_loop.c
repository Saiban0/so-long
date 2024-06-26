/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:11:31 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/20 21:21:39 by bchedru          ###   ########.fr       */
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
	if (game->ticks % 45 == 0)
		move_monsters(game, game->monster_array);
	game->ticks++;
}

void	collectible_collision(t_so_long *game)
{
	t_coord	temp;

	if (game->map[game->player_coords.x][game->player_coords.y] == 'C')
	{
		game->map[game->player_coords.x][game->player_coords.y] = '0';
		temp.x = game->player_coords.x;
		temp.y = game->player_coords.y;
		temp.z = 6;
		load_image(game->mlx_ptr, temp, game->floor_image, 1);
		game->collectibles++;
	}
}

int	get_monster_id(t_so_long *game, t_coord coords)
{
	int	i;

	i = 0;
	while (game->monster_array[i])
	{
		if (game->monster_array[i]->coords.x == coords.x
			&& game->monster_array[i]->coords.y == coords.y)
			return (i);
		i++;
	}
	return (-1);
}

void	kill_monster(t_so_long *game, t_coord coords)
{
	int	id;

	id = get_monster_id(game, coords);
	if (id == -1)
		safe_exit("Monster deletion failed\n", game);
	game->map[coords.x][coords.y] = '0';
	game->monster_array[id]->alive = 0;
	(&game->monster_image.round->instances[id])->enabled = 0;
	(&game->monster_image.square->instances[id])->enabled = 0;
}
