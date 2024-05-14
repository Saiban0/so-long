/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:05:05 by bchedru           #+#    #+#             */
/*   Updated: 2024/05/14 18:15:48 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_name(char	*map_name)
{
	int	i;
	int len;

	i = 0;
	len = ft_strlen(map_name) - 4;
	if (len < 5)
		return (-1);
	while (i < len)
		i++;
	if (map_name[i++] != '.')
		return (1);
	if (map_name[i++] != 'b')
		return (1);
	if (map_name[i++] != 'e')
		return (1);
	if (map_name[i++] != 'r')
		return (1);
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
		return (NULL);
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
	
	return (0);
}
