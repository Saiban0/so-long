/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:12:16 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/11 12:22:49 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


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
	exit(0);
}

void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}
