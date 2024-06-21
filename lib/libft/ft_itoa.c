/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:45:13 by bchedru           #+#    #+#             */
/*   Updated: 2023/10/26 14:58:33 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa2(long longn, int len, char *res)
{
	if (longn < 0)
	{
		longn = -longn;
		*res++ = '-';
		--len;
	}
	res[len] = '\0';
	while (len--)
	{
		res[len] = '0' + longn % 10;
		longn /= 10;
	}
}

char	*ft_itoa(int n)
{
	long	longn;
	int		len;
	char	*res;

	longn = n;
	len = 1;
	if (longn < 0)
	{
		longn = -longn;
		++len;
	}
	while (longn > 9)
	{
		longn /= 10;
		++len;
	}
	res = (char *) malloc(len + 1);
	if (res)
		itoa2(n, len, res);
	return (res);
}
