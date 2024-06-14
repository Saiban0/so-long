/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:21:00 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/13 19:47:46 by bchedru          ###   ########.fr       */
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

// static void	player_image_placement(t_so_long *game, int i, int j)
// {
// 	mlx_image_to_window(game->mlx_ptr,
// 	game->player_image, j * 32 , i * 32);
// 	// game->player_image->instances->z = 1;
// }

// static void	floor_image_placement(t_so_long *game, int i, int j)
// {
// 	mlx_image_to_window(game->mlx_ptr,
// 	game->floor_image, j * 32 , i * 32);
// 	// game->floor_image->instances->z = 0;
// }

void	images_placement(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx_ptr,
					game->wall_image, j * 32, i * 32);
			if (game->map[i][j] == '0')
				mlx_image_to_window(game->mlx_ptr,
					game->floor_image, j * 32, i * 32);
			if (game->map[i][j] == 'P')
				mlx_image_to_window(game->mlx_ptr,
					game->player_image, j * 32, i * 32);
			if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx_ptr,
					game->exit_image, j * 32, i * 32);
			if (game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx_ptr,
					game->collectible_image, j * 32, i * 32);
			j++;
		}
		i++;
	}
}
