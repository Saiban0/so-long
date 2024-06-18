/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monsters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:16:38 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/18 16:43:55 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_move(t_so_long *game, t_monster monster,int mvt_y)
{
	int	new_y;

	new_y = monster.coords.y + mvt_y;
	if (ft_strchr("1CEM", game->map[monster.coords.x][new_y]))
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
	(&game->monster_image->instances[monster->id])->x -= SO_LONG_UNIT;
}

static void	monster_move_right(t_so_long *game, t_monster *monster)
{
	t_coord	temp;

	temp.x = monster->coords.x;
	temp.y = monster->coords.y;
	monster->coords.y++;
	game->map[temp.x][temp.y] = '0';
	game->map[monster->coords.x][monster->coords.y] = 'M';
	(&game->monster_image->instances[monster->id])->x += SO_LONG_UNIT;
}

void	move_monsters(t_so_long *game, t_monster **array)
{
	int	i;

	i = -1;
	while (++i < game->max_monsters)
	{
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

static	t_monster	*create_new_monster(t_coord coords, int id)
{
	t_monster		*new;

	new = malloc(sizeof(t_monster));
	new->coords = coords;
	new->direction = "left";
	new->id = id;
	return (new);
}

void	initialize_monster_array(t_so_long *game)
{
	int	cpt;
	t_coord	temp;

	temp.x = 0;
	cpt = 0;
	game->monster_array = malloc(game->max_monsters * sizeof(t_monster *));
	if (!game->monster_array)
		return ;
	while (game->map[temp.x])
	{
		temp.y = 0;
		while (game->map[temp.x][temp.y])
		{
			temp.y++;
			if(game->map[temp.x][temp.y] == 'M')
			{
				game->monster_array[cpt] = create_new_monster(temp, cpt);
				cpt++;
			}
		}
		temp.x++;
	}
}

void	update_monster_array(t_so_long *game)
{
	int			i;
	t_coord		old_coords;

	i = -1;
	while (++i < game->max_monsters)
	{
		old_coords = (*game->monster_array)[i].coords;
		if (ft_strcmp((*game->monster_array)[i].direction, "right"))
			if (!ft_strchr("1EC", game->map[old_coords.y][old_coords.x + 1]))
			{
				(*game->monster_array)[i].coords.x++;
				update_map(game, (*game->monster_array)[i].coords);
			}
		if (ft_strcmp((*game->monster_array)[i].direction, "left"))
			if (!ft_strchr("1EC", game->map[old_coords.y][old_coords.x - 1]))
			{
				(*game->monster_array)[i].coords.x++;
				update_map(game, (*game->monster_array)[i].coords);
			}
	}
}