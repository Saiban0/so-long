/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:05:05 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/11 12:56:15 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
				(game->map_height + 3) * 32, "OUI", true);
	else
		game->mlx_ptr = mlx_init((game->map_width + 5) * 32,
				(game->map_height + 1) * 32, "OUI", true);
	if (!game->mlx_ptr)
		safe_exit("mlx_init crashed", game);
	return (0);
}
