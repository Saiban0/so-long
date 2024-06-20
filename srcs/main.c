/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:05:05 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/20 15:34:59 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_so_long	*game;

	(void)keydata;
	game = (t_so_long *)param;
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_W))
		player_move_up(game);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_A))
		player_move_left(game);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_S))
		player_move_down(game);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_D))
		player_move_right(game);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_ESCAPE))
		safe_exit("Clean exit\n", game);
	if (mlx_is_key_down(game->mlx_ptr, MLX_KEY_P))
		print_map(game);
}

int	main(int argc, char **argv)
{
	t_so_long	*game;

	game = malloc(sizeof(t_so_long));
	if (!game)
		return (0);
	if (argc != 2)
		safe_exit("Not enough/too much arguments", game);
	check_path(argv[1], game);
	open_file(game, argv[1]);
	game->mlx_ptr = mlx_init((game->map_width + 1) * SO_LONG_UNIT,
			(game->map_height + 1) * SO_LONG_UNIT, "So-long", true);
	textures_init(game);
	images_placement(game);
	initialize_starting_variables(game);
	mlx_key_hook(game->mlx_ptr, &keyhook, game);
	mlx_loop_hook(game->mlx_ptr, (void *)game_loop, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
