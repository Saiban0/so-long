/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:11:31 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/17 15:15:25 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_loop(t_so_long *game)
{
	if (game->collectibles == game->max_collectibles)
		game->collected_all = 1;
}

void	collectible_collision(t_so_long *game)
{
	t_coord	temp;

	temp.x = game->player_coords.x;
	temp.y = game->player_coords.y;
	temp.z = 10;
	select_image_load(game, temp);
	game->collectibles++;
}
