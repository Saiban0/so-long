/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:51:56 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/18 18:36:07 by bchedru          ###   ########.fr       */
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
	game->moves_str = mlx_put_string(game->mlx_ptr, nbr, 16, 8);
	free(nbr);
}
