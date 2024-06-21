/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:44:58 by bchedru           #+#    #+#             */
/*   Updated: 2024/05/23 17:35:58 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putdigit(size_t n, char *base, size_t base_len)
{
	if (n >= base_len)
		ft_putdigit(n / base_len, base, base_len);
	ft_putchar(base[n % base_len]);
}

int	ft_putnbr_base(size_t n, char *base)
{
	int			len;
	size_t		base_len;

	len = 1;
	base_len = ft_strlen(base);
	ft_putdigit(n, base, base_len);
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}
