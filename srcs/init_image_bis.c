/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:29:21 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/21 17:00:55 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	switch_square_monster_to_round(t_so_long *game, int i)
{
	(&game->monster_image.round->instances[i])->enabled = 1;
	(&game->monster_image.square->instances[i])->enabled = 0;
}

void	switch_round_monster_to_square(t_so_long *game, int i)
{
	(&game->monster_image.round->instances[i])->enabled = 0;
	(&game->monster_image.square->instances[i])->enabled = 1;
}

void	close_hook(t_so_long *game)
{
	safe_exit("Clean exit\n", game);
}

void	pre_initialize_map_variables(t_so_long *game)
{
	mlx_image_t	*tmp;

	tmp = NULL;
	tmp = mlx_put_string(game->mlx_ptr, "Steps", 16, 2);
	mlx_set_instance_depth(tmp->instances, 15);
	tmp = mlx_put_string(game->mlx_ptr, "Lives", 16, 18);
	mlx_set_instance_depth(tmp->instances, 15);
	game->moves_str = mlx_put_string(game->mlx_ptr, " ", -10, -10);
	game->lives_str = mlx_put_string(game->mlx_ptr, " ", -10, -10);
	display_movement(game);
	display_lives(game);
	initialize_map_variables(game);
	if (game->max_monsters)
		initialize_monster_array(game);
}
