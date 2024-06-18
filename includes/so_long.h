/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:05:32 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/18 17:22:26 by bchedru          ###   ########.fr       */
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

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
}			t_coord;

typedef struct s_monster
{
	t_coord		coords;
	char		*direction;
	int			id;
}			t_monster;

typedef struct s_so_long
{
	mlx_t				*mlx_ptr;
	char				**map;
	int					map_height;
	int					map_width;
	int					movement_count;
	int					collectibles;
	int					max_collectibles;
	int					player_health;
	int					max_monsters;
	bool				collected_all;
	t_coord				player_coords;
	t_monster			**monster_array;
	mlx_image_t			*wall_image;
	mlx_image_t			*player_image;
	mlx_image_t			*exit_image;
	mlx_image_t			*collectible_image;
	mlx_image_t			*floor_image;
	mlx_image_t			*monster_image;
	unsigned long long	ticks;
}				t_so_long;

# define SO_LONG_UNIT 32
# define PLAYER_HEALTH 5

/*   Parsing   */
void	check_path(char	*path, t_so_long *game);
void	open_file(t_so_long *game, char *map_path);
int		check_length(char	*line, size_t width);
int		parse(int depth, t_so_long *game, int fd);
int		check_characters(t_so_long	*game);
int		check_surrounded(t_so_long	*game);
int		check_special_character_occurences(t_so_long *game);
void	initialize_starting_variables(t_so_long *game);

/*   Error Management   */
void	safe_exit(char	*error_msg, t_so_long	*game);

/*  Images init  */
void	textures_init(t_so_long *game);
void	load_image(mlx_t *mlx, t_coord coord, mlx_image_t *image, bool enabled);
void	image_placement_bis(t_so_long *game, t_coord coords);
void	images_placement(t_so_long *game);

/*  Player movements  */
void	player_move_up(t_so_long *game);
void	player_move_down(t_so_long *game);
void	player_move_left(t_so_long *game);
void	player_move_right(t_so_long *game);

/*  Monsters  */
t_monster	*create_new_monster(t_coord coords, int id);
void	move_monsters(t_so_long *game, t_monster **array);
void	initialize_monster_array(t_so_long *game);

/*  Game loop  */
void	game_loop(t_so_long *game);

/*  Utils   */
void	print_map(t_so_long *game);
void	collectible_collision(t_so_long *game);
void	update_map(t_so_long *game, t_coord coords);


#endif