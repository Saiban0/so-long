/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:05:32 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/12 20:28:16 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include "../lib/libft/libft.h"
# include "MLX42.h"

typedef struct s_so_long
{
	mlx_t	*mlx_ptr;
	char	**map;
	int		map_height;
	int		map_width;
	int		player_x;
	int		player_y;
	mlx_image_t	*wall_image;
	mlx_image_t	*player_image;
	mlx_image_t	*exit_image;
	mlx_image_t	*collectible_image;
	mlx_image_t	*floor_image;
}				t_so_long;

/*   Parsing   */
void	check_path(char	*path, t_so_long *game);
void	open_file(t_so_long *game, char *map_path);
int		check_length(char	*line, size_t width);
int		parse(int depth, t_so_long *game, int fd);
int		check_characters(t_so_long	*game);
int		check_surrounded(t_so_long	*game);

/*   Error Management   */
void	safe_exit(char	*error_msg, t_so_long	*game);
void	free_matrix(char **matrix);

/*  Images init  */
void	textures_init(t_so_long *game);
void	texture_placement(t_so_long *game);

/*  Movements  */
void	player_move_up(t_so_long *game);
void	player_move_down(t_so_long *game);
void	player_move_left(t_so_long *game);
void	player_move_right(t_so_long *game);

/*  Game loop  */
void	game_loop(t_so_long *game);

#endif