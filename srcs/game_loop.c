/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:11:31 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/14 22:09:33 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_loop(t_so_long *game)
{
	if (game->map[game->player_coords.x][game->player_coords.y] == 'C')
		game->collectibles++;
	if (game->collectibles == game->max_collectibles)
		game->collected_all = 1;
}
