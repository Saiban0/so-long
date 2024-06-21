/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:26:35 by bchedru           #+#    #+#             */
/*   Updated: 2023/10/24 14:23:15 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		words++;
		while (s[i] == c && s[i])
			i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < words && *s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			res[i] = ft_substr(s, 0, (ft_strchr(s, c) - s));
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	res[i] = NULL;
	return (res);
}
