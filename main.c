/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:05:05 by bchedru           #+#    #+#             */
/*   Updated: 2024/05/15 17:13:10 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_name(char *map_name)
{
	int		i;
	int		len;
	char	*ber;

	i = 0;
	len = ft_strlen(map_name) - 5;
	ber = ".ber";
	if (len < 5)
		return (-1);
	while (i < len)
		i++;
	while (map_name[i++])
	{
		if (map_name[i] != *ber++)
		{
			ft_printf("Map not in .ber\n");
			return (1);
		}
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
		return (NULL);
	*map = get_next_line(file);
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
