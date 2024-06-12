/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:12:16 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/12 18:22:41 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	safe_exit(char	*error_msg, t_so_long	*game)
{
	if (*error_msg != '\0')
		ft_printf("%s\n", error_msg);
	if (game->map)
	{
		free_matrix(game->map);
		free(game->map);
	}
	if (game->mlx_ptr)
	{
		mlx_close_window(game->mlx_ptr);
		mlx_terminate(game->mlx_ptr);
	}
	if (game)
		free(game);
	exit(0);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (NULL == matrix || NULL == *matrix)
		return ;
	while (matrix[++i])
		free(matrix[i]);
}
