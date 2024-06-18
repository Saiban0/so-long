/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:51:56 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/18 19:10:13 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_movement(t_so_long *game)
{
	char	*str;
	char	*nbr;

	mlx_delete_image(game->mlx_ptr, game->moves_str);
	str = " Movements";
	nbr = ft_itoa(game->movement_count);
	ft_strcat(nbr,str);
	game->moves_str = mlx_put_string(game->mlx_ptr, nbr, 16, 2);
	free(nbr);
}

void	display_lives(t_so_long *game)
{
	char	*str;
	char	*nbr;

	mlx_delete_image(game->mlx_ptr, game->lives_str);
	str = " Lives";
	nbr = ft_itoa(game->player_health);
	ft_strcat(nbr,str);
	game->lives_str = mlx_put_string(game->mlx_ptr, nbr, 16, 18);
	free(nbr);
}
