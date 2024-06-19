/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:51:56 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/19 16:46:40 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_movement(t_so_long *game)
{
	char	*nbr;

	if (!game->moves_str)
		game->moves_str = mlx_put_string(game->mlx_ptr, " ", -10, -10);
	mlx_delete_image(game->mlx_ptr, game->moves_str);
	nbr = ft_itoa(game->movement_count);
	ft_strcat(nbr, " Movements");
	game->moves_str = mlx_put_string(game->mlx_ptr, nbr, 16, 2);
	free(nbr);
}

void	display_lives(t_so_long *game)
{
	char	*nbr;

	if (!game->lives_str)
		game->lives_str = mlx_put_string(game->mlx_ptr, " ", -10, -10);
	mlx_delete_image(game->mlx_ptr, game->lives_str);
	nbr = ft_itoa(game->player_health);
	ft_strcat(nbr, " Lives");
	game->lives_str = mlx_put_string(game->mlx_ptr, nbr, 16, 18);
	free(nbr);
}
