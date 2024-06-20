/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:51:56 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/20 18:20:52 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_movement(t_so_long *game)
{
	char		*nbr;
	
	if (!game->moves_str)
		game->moves_str = mlx_put_string(game->mlx_ptr, " ", -10, -10);
	mlx_delete_image(game->mlx_ptr, game->moves_str);
	nbr = ft_itoa(game->movement_count);
	game->moves_str = mlx_put_string(game->mlx_ptr, nbr, 72, 2);
	free(nbr);
}

void	display_lives(t_so_long *game)
{
	char	*nbr;

	if (!game->lives_str)
		game->lives_str = mlx_put_string(game->mlx_ptr, " ", -10, -10);
	mlx_delete_image(game->mlx_ptr, game->lives_str);
	nbr = ft_itoa(game->player_health);
	game->lives_str = mlx_put_string(game->mlx_ptr, nbr, 72, 18);
	free(nbr);
}
