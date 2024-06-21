/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:24:15 by bchedru           #+#    #+#             */
/*   Updated: 2023/10/23 13:59:07 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(const char s, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (in_set(((char )*s1), set) == 1)
			s1++;
		else
			break ;
	}
	size = ft_strlen(s1);
	while (size != 0)
	{
		if (in_set(s1[size - 1], set) == 1)
			size--;
		else
			break ;
	}
	res = (char *)malloc(size * sizeof(char) + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, (char *)s1, size + 1);
	return (res);
}
