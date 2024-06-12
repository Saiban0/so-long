/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:25:02 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/12 20:25:58 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	is_valid_move(t_so_long *game, int mvt_x, int mvt_y)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + mvt_x;
	new_y = game->player_y + mvt_y;
	if (ft_strchr("0C" ,game->map[new_x][new_y]) == NULL)
		return (1);
	return (0);
}

void	player_move_up(t_so_long *game)
{
	if (!is_valid_move(game, 0, -1))
		game->player_y -= 1;
}

void	player_move_down(t_so_long *game)
{
	if (!is_valid_move(game, 0, 1))
		game->player_y += 1;
}

void	player_move_left(t_so_long *game)
{
	if (!is_valid_move(game, -1, 0))
		game->player_x -= 1;
}

void	player_move_right(t_so_long *game)
{
	if (!is_valid_move(game, 1, 0))
		game->player_x += 1;
}
