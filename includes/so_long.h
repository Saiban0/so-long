/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:05:32 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/11 12:48:20 by bchedru          ###   ########.fr       */
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

typedef struct	s_so_long
{
	mlx_t	*mlx_ptr;
	char	**map;
	int		map_height;
	int		map_width;
}				t_so_long;


/*   Parsing   */
void	check_path(char	*path, t_so_long *game);
void	open_file(t_so_long *game, char *map_path);
int		check_length(char	*line, size_t width);
int		parse(int depth, t_so_long *game, int fd);

/*   Error Management   */
void	safe_exit(char	*error_msg, t_so_long	*game);
void	free_matrix(char **argv);



#endif
