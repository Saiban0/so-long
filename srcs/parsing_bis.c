/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:38:55 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/20 21:21:42 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_special_character_occurences(t_so_long *game)
{
	int	i;
	int	j;
	int	p_count;
	int	e_count;

	i = 0;
	p_count = 0;
	e_count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				p_count++;
			if (game->map[i][j] == 'E')
				e_count++;
			j++;
		}
		i++;
	}
	if (p_count != 1 || e_count != 1)
		return (1);
	return (0);
}

void	map_pathway(char	**map, int y, int x)
{
	map[y][x] *= -1;
	if (ft_strchr("E0CM", map[y + 1][x]))
		map_pathway(map, y + 1, x);
	if (ft_strchr("E0CM", map[y - 1][x]))
		map_pathway(map, y - 1, x);
	if (ft_strchr("E0CM", map[y][x + 1]))
		map_pathway(map, y, x + 1);
	if (ft_strchr("E0CM", map[y][x - 1]))
		map_pathway(map, y, x - 1);
}

static void	post_pathway_variable_test(int collectibles, t_so_long *game)
{
	if (collectibles != game->max_collectibles)
		safe_exit("The player can't optain every collectible\n", game);
	if (game->can_reach_exit == false)
		safe_exit("The player can't reach the exit\n", game);
}

void	post_pathway(char	**map, t_so_long *game)
{
	int	i;
	int	j;
	int	collectible_found;

	i = 0;
	collectible_found = 0;
	game->can_reach_exit = false;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] < 0)
			{
				map[i][j] *= -1;
				if (map[i][j] == 'C')
					collectible_found++;
				else if (map[i][j] == 'E')
					game->can_reach_exit = true;
			}
		}
	}
	post_pathway_variable_test(collectible_found, game);
}
