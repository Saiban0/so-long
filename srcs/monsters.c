/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monsters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:16:38 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/20 17:36:19 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_move(t_so_long *game, t_monster monster, int mvt_y)
{
	int	new_y;

	new_y = monster.coords.y + mvt_y;
	if (monster.alive == 0)
		return (0);
	if (ft_strchr("1CEM", game->map[monster.coords.x][new_y]))
		return (0);
	if (monster.coords.x == game->player_coords.x
		&& game->player_coords.y == new_y)
		return (0);
	return (1);
}

static void	monster_move_left(t_so_long *game, t_monster *monster)
{
	t_coord	temp;

	temp.x = monster->coords.x;
	temp.y = monster->coords.y;
	monster->coords.y--;
	game->map[temp.x][temp.y] = '0';
	game->map[monster->coords.x][monster->coords.y] = 'M';
	(&game->monster_image.square->instances[monster->id])->x -= SO_LONG_UNIT;
	(&game->monster_image.round->instances[monster->id])->x -= SO_LONG_UNIT;
}

static void	monster_move_right(t_so_long *game, t_monster *monster)
{
	t_coord	temp;

	temp.x = monster->coords.x;
	temp.y = monster->coords.y;
	monster->coords.y++;
	game->map[temp.x][temp.y] = '0';
	game->map[monster->coords.x][monster->coords.y] = 'M';
	(&game->monster_image.square->instances[monster->id])->x += SO_LONG_UNIT;
	(&game->monster_image.round->instances[monster->id])->x += SO_LONG_UNIT;
}

void	move_monsters(t_so_long *game, t_monster **array)
{
	int	i;

	i = -1;
	while (++i < game->max_monsters)
	{
		if ((&game->monster_image.round->instances[i])->enabled == 1)
			switch_round_monster_to_square(game, i);
		else if ((&game->monster_image.square->instances[i])->enabled == 1)
			switch_square_monster_to_round(game, i);
		if (ft_strcmp((*array[i]).direction, "left") == 0
			&& is_valid_move(game, (*array[i]), -1))
			monster_move_left(game, array[i]);
		else if (ft_strcmp((*array[i]).direction, "left") == 0
			&& !is_valid_move(game, (*array[i]), -1))
			(*array[i]).direction = "right";
		if (ft_strcmp((*array[i]).direction, "right") == 0
			&& is_valid_move(game, (*array[i]), 1))
			monster_move_right(game, array[i]);
		else if (ft_strcmp((*array[i]).direction, "right") == 0
			&& !is_valid_move(game, (*array[i]), 1))
			(*array[i]).direction = "left";
	}
}

t_monster	*create_new_monster(t_coord coords, int id)
{
	t_monster		*new;

	new = malloc(sizeof(t_monster));
	new->coords = coords;
	new->direction = "left";
	new->id = id;
	new->alive = 1;
	return (new);
}
