/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:25:01 by bchedru           #+#    #+#             */
/*   Updated: 2023/10/19 21:42:05 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nb)
{
	int	value;
	int	i;
	int	minus;

	value = 0;
	i = 0;
	minus = 1;
	while (nb[i] == ' ' || nb[i] == '\t' || nb[i] == '\n'
		|| nb[i] == '\v' || nb[i] == '\f' || nb[i] == '\r')
		i++;
	if (nb[i] == '-')
	{
		minus = -minus;
		i++;
	}
	else if (nb[i] == '+')
		i++;
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		value = (value * 10 + nb[i] - '0');
		i++;
	}
	return (value * minus);
}
