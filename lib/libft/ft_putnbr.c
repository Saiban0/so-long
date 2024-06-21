/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:27:48 by bchedru           #+#    #+#             */
/*   Updated: 2024/05/23 17:30:29 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putdigit(unsigned long int n)
{
	if (n > 9)
		ft_putdigit(n / 10);
	ft_putchar((n % 10) + '0');
}

int	ft_putnbr(int n)
{
	long int	longn;
	int			len;

	longn = (long int)n;
	len = 1;
	if (n < 0)
	{
		ft_putchar('-');
		len++;
		longn = -longn;
	}
	ft_putdigit(longn);
	while (longn > 9)
	{
		longn /= 10;
		len++;
	}
	return (len);
}
