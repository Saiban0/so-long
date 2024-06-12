/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:05:05 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/12 20:40:31 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	keyhook(mlx_key_data_t keydata, void *param)
// {
// 	t_so_long	*game;

// 	(void)keydata;
// 	game = (t_so_long *)param;
// 	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_W))
// 		move_up(game);
// 		game->player_image->instances[0] -= 32;
// }

int	main(int argc, char **argv)
{
	t_so_long	*game;

	game = malloc(sizeof(t_so_long));
	if (argc != 2)
		safe_exit("Not enough/too much arguments", game);
	check_path(argv[1], game);
	open_file(game, argv[1]);
	if (game->map_width > 15)
		game->mlx_ptr = mlx_init((game->map_width + 1) * 32,
				(game->map_height + 3) * 32, "jemlessaucisses", true);
	else
		game->mlx_ptr = mlx_init((game->map_width + 5) * 32,
				(game->map_height + 1) * 32, "jemlessaucisses", true);
	textures_init(game);
	// mlx_key_hook(game->mlx_ptr, &keyhook, &game);
	mlx_loop_hook(game->mlx_ptr, (void *)game_loop, &game);
	mlx_loop(game->mlx_ptr);
	safe_exit("", game);
	return (0);
}
