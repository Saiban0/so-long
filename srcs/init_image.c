/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:21:00 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/17 20:33:57 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	textures_init(t_so_long *game)
{
	mlx_texture_t	*temp;

	temp = mlx_load_png("sprite/wall.png");
	game->wall_image = mlx_texture_to_image(game->mlx_ptr, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("sprite/exit.png");
	game->exit_image = mlx_texture_to_image(game->mlx_ptr, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("sprite/floor.png");
	game->floor_image = mlx_texture_to_image(game->mlx_ptr, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("sprite/collectible.png");
	game->collectible_image = mlx_texture_to_image(game->mlx_ptr, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("sprite/player.png");
	game->player_image = mlx_texture_to_image(game->mlx_ptr, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("sprite/monster.png");
	game->monster_image = mlx_texture_to_image(game->mlx_ptr, temp);
	mlx_delete_texture(temp);
}

void	load_image(mlx_t *mlx, t_coord coord, mlx_image_t *image, bool enabled)
{
	mlx_image_to_window(mlx, image, coord.y * 32, coord.x * 32);
	mlx_set_instance_depth(&image->instances[image->count - 1], coord.z);
	image->instances->enabled = enabled;
}

void	image_placement_bis(t_so_long *game, t_coord coords)
{
	if (game->map[coords.x][coords.y] == 'P')
	{
		coords.z = 10;
		load_image(game->mlx_ptr, coords, game->player_image, 1);
		coords.z = 0;
		load_image(game->mlx_ptr, coords, game->floor_image, 1);
	}
	if (game->map[coords.x][coords.y] == 'E')
	{
		coords.z = 5;
		load_image(game->mlx_ptr, coords, game->exit_image, 1);
	}
	if (game->map[coords.x][coords.y] == 'C')
	{
		coords.z = 5;
		load_image(game->mlx_ptr, coords, game->collectible_image, 1);
	}
	if (game->map[coords.x][coords.y] == 'M')
	{
		coords.z = 5;
		load_image(game->mlx_ptr, coords, game->monster_image, 1);
		coords.z = 0;
		load_image(game->mlx_ptr, coords, game->floor_image, 1);
	}
}

void	images_placement(t_so_long *game)
{
	t_coord	co;

	co.x = 0;
	while (game->map[co.x])
	{
		co.y = 0;
		while (game->map[co.x][co.y])
		{
			co.z = 0;
			load_image(game->mlx_ptr, co, game->floor_image, 1);
			if (game->map[co.x][co.y] == '1')
			{
				co.z = 5;
				load_image(game->mlx_ptr, co, game->wall_image, 1);
			}
			// if (game->map[co.x][co.y] == '0')
			// {
			// 	co.z = 0;
			// 	load_image(game->mlx_ptr, co, game->floor_image, 1);
			// }
			else
				image_placement_bis(game, co);
			co.y++;
		}
		co.x++;
	}
}
