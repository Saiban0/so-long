/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:21:00 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/14 20:18:52 by bchedru          ###   ########.fr       */
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
}

void	load_image(mlx_t *mlx, t_coord coord, mlx_image_t *image, bool enabled)
{
	mlx_image_to_window(mlx, image, coord.y * 32, coord.x * 32);
	mlx_set_instance_depth(&image->instances[image->count - 1], coord.z);
	image->instances->enabled = enabled;
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
			if (game->map[co.x][co.y] == '1')
			{
				co.z = 5;
				load_image(game->mlx_ptr, co,game->wall_image,1);
			}
			if (game->map[co.x][co.y] == '0')
			{
				co.z = 0;
				load_image(game->mlx_ptr, co,game->floor_image,1);
			}
			if (game->map[co.x][co.y] == 'P')
			{
				co.z = 10;
				load_image(game->mlx_ptr, co,game->player_image,1);
			}
			if (game->map[co.x][co.y] == 'E')
			{
				co.z = 5;
				load_image(game->mlx_ptr, co,game->exit_image,1);
			}
			if (game->map[co.x][co.y] == 'C')
			{
				co.z = 5;
				load_image(game->mlx_ptr, co,game->collectible_image,1);
			}
			co.y++;
		}
		co.x++;
	}
}
