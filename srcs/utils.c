/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:09:20 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/20 21:36:33 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			ft_printf("%c", game->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n\n");
}

void	open_file(t_so_long *game, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (!fd)
		safe_exit("Failed to open file\n", game);
	if (fd == -1)
		safe_exit("File not found.\n", game);
	game->map_height = 0;
	game->map_width = 0;
	if (parse(0, game, fd) == -1)
		safe_exit("Map is not rectangular\n", game);
	if (game->map_height < 4 && game->map_width < 4)
		safe_exit("Map is too small.\n", game);
	if (check_characters(game) == 1)
		safe_exit("Characters in map not defined\n", game);
	if (check_surrounded(game) == 1)
		safe_exit("Map is not entirely surrounded by walls\n", game);
	if (check_special_character_occurences(game))
		safe_exit("Map must have only one player and one exit\n", game);
}

static void	initialize_map_variables(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_coords.x = i;
				game->player_coords.y = j;
				game->player_coords.z = 10;
			}
			if (game->map[i][j] == 'C')
				game->max_collectibles++;
			if (game->map[i][j] == 'M')
				game->max_monsters++;
			j++;
		}
		i++;
	}
	if (game->max_collectibles < 1)
		safe_exit("Map must have at least 1 collectible\n", game);
}

static void	initialize_monster_array(t_so_long *game)
{
	int		cpt;
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
			if (game->map[temp.x][temp.y] == 'M')
			{
				game->monster_array[cpt] = create_new_monster(temp, cpt);
				cpt++;
			}
		}
		temp.x++;
	}
}

void	initialize_starting_variables(t_so_long *game)
{
	mlx_image_t	*tmp;

	tmp = NULL;
	tmp = mlx_put_string(game->mlx_ptr, "Steps", 16, 2);
	tmp = mlx_put_string(game->mlx_ptr, "Lives", 16, 18);
	game->movement_count = 0;
	game->player_health = PLAYER_HEALTH;
	game->max_collectibles = 0;
	game->collectibles = 0;
	game->ticks = 0;
	game->max_monsters = 0;
	game->moves_str = mlx_put_string(game->mlx_ptr, " ", -10, -10);
	game->lives_str = mlx_put_string(game->mlx_ptr, " ", -10, -10);
	display_movement(game);
	display_lives(game);
	initialize_map_variables(game);
	if (game->max_monsters)
		initialize_monster_array(game);
}
