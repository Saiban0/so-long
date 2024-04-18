/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:05:05 by bchedru           #+#    #+#             */
/*   Updated: 2024/04/18 16:42:03 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_name(char	*map_name)
{
	
}

char	**parse_map(char *argv1)
{
	char	**map;
	int		file;

	map = NULL;
	file = open(argv1, O_RDONLY);
	if (file == -1)
		return (NULL);
	while(*map != NULL)
	{
		*map = get_next_line(file);
		map++;
	}
	close(file);
	return (map);
}

int	main(int argc, char **argv)
{
	char	**map;

	map = NULL;
	if (argc == 1)
		return (1);
	map = parse_map(argv[1]);
	if (map == NULL)
		return(1);
	
	return (0);
}
