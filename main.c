/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:05:05 by bchedru           #+#    #+#             */
/*   Updated: 2024/05/23 16:33:18 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	check_map_name(char *map_name)
{
	if (ft_strncmp(map_name + ft_strlen(map_name) - 4, ".ber", 4))
	{
		ft_printf("Map not in .ber\n");
		return (1);
	}
	return (0);
}

char	**parse_map(char *argv1)
{
	char	**map;
	int		file;

	map = NULL;
	if (check_map_name(argv1))
		return (NULL);
	file = open(argv1, O_RDONLY);
	if (file == -1)
	{
		ft_printf("Map not found\n");
		return (NULL);
	}
	map = get_next_line(file);
	while(map != NULL)
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
	else
	{
		ft_printf("oui\n");
		while(*map++)
			ft_printf("%s", *map);
	}
	return (0);
}
