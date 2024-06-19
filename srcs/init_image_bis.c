/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:29:21 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/19 19:04:00 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	switch_square_monster_to_round(t_so_long *game, int i)
{
	(void)game;
	(void)i;
	// (&game->monster_image.round->instances[i])->enabled = 0;
	// (&game->monster_image.square->instances[i])->enabled = 1;
}

void	switch_round_monster_to_square(t_so_long *game, int i)
{
	(void)game;
	(void)i;
	// (&game->monster_image.round->instances[i])->enabled = 1;
	// (&game->monster_image.square->instances[i])->enabled = 0;
}
