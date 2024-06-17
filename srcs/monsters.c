/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monsters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:16:38 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/17 20:12:34 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	is_valid_move(t_so_long *game, t_monster monster,int mvt_x)
{
	int	new_x;

	new_x = monster.coords.x + mvt_x;
	if (!(new_x >= 1 && new_x < game->map_height - 1))
		return (0);
	if (ft_strchr("1CEM", game->map[new_x][monster.coords.y]))
		return (0);
	return (1);
}

static void	monster_move_left(t_so_long *game, t_monster monster)
{
	t_coord	temp;

	temp.x = monster.coords.x;
	temp.y = monster.coords.y;
	temp.z = 6;
	monster.coords.x--;
	game->map[temp.x][temp.y] = '0';
	game->map[monster.coords.x][monster.coords.y] = 'M';
	update_map(game, temp);
}

static void	monster_move_right(t_so_long *game, t_monster monster)
{
	t_coord	temp;

	temp.x = monster.coords.x;
	temp.y = monster.coords.y;
	temp.z = 6;
	monster.coords.x++;
	game->map[temp.x][temp.y] = '0';
	game->map[monster.coords.x][monster.coords.y] = 'M';
	update_map(game, temp);
}

void	move_monsters(t_so_long *game, t_monster *array)
{
	int	i;

	i = 0;
	while (&array[i])
	{
		if (ft_strcmp(array[i].direction, "left") == 0  
				&& is_valid_move(game, array[i], -1))
			monster_move_left(game, array[i]);
		else if (ft_strcmp(array[i].direction, "left") == 0
				&& is_valid_move(game, array[i], 1))
		{
			array[i].direction = "right";
			monster_move_right(game, array[i]);
		}
		if (ft_strcmp(array[i].direction, "right") == 0
				&& is_valid_move(game, array[i], 1))
			monster_move_right(game, array[i]);
		else if (ft_strcmp(array[i].direction, "right") == 0
				&& is_valid_move(game, array[i], -1))
		{
			array[i].direction = "left";
			monster_move_left(game, array[i]);
		}
		i++;
	}
}

static	t_monster	create_new_monster(t_coord coords)
{
	t_monster		new;

	new.coords = coords;
	new.direction = "left";
	return (new);
}

void	initialize_monster_array(t_so_long *game)
{
	int	i;
	int	j;
	int	cpt;
	t_coord	temp;

	i = 0;
	cpt = 0;
	while (game->map[i])
	{
		temp.x = i;
		j = 0;
		while (game->map[i][j])
		{
			temp.y = j;
			if(game->map[i][j] == 'M')
			{
				game->monster_array[cpt] = create_new_monster(temp);
				cpt++;
			}
			j++;
		}
		i++;
	}
}

void	update_monster_array(t_so_long *game)
{
	int			i;
	t_coord		old_coords;

	i = -1;
	while (++i < game->max_monsters)
	{
		old_coords = game->monster_array[i].coords;
		if (ft_strcmp(game->monster_array[i].direction, "right"))
			if (!ft_strchr("1EC", game->map[old_coords.y][old_coords.x + 1]))
			{
				game->monster_array[i].coords.x++;
				update_map(game, game->monster_array[i].coords);
			}
		if (ft_strcmp(game->monster_array[i].direction, "left"))
			if (!ft_strchr("1EC", game->map[old_coords.y][old_coords.x - 1]))
			{
				game->monster_array[i].coords.x++;
				update_map(game, game->monster_array[i].coords);
			}
	}
}