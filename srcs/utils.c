/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:09:20 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/14 21:42:11 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			ft_printf("%c", game->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n\n");
}

void	open_file(t_so_long *game, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (!fd)
		safe_exit("File not found.", game);
	if (parse(0, game, fd) == -1)
		safe_exit("Map is not rectangular", game);
	if (game->map_height < 4 && game->map_width < 4)
		safe_exit("Map is too small.", game);
	if (check_characters(game) == 1)
		safe_exit("Characters in map not defined", game);
	if (check_surrounded(game) == 1)
		safe_exit("Map is not entirely surrounded by walls", game);
}
