/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:41:10 by bchedru           #+#    #+#             */
/*   Updated: 2024/05/23 17:09:47 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!res)
		return (NULL);
	while (s1[j])
	{
		res[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		j++;
		i++;
	}
	res[i] = '\0';
	free((char *)s1);
	return (res);
}

int	ft_find_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_calloc_gnl(int nmemb, int size)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(nmemb * size);
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
