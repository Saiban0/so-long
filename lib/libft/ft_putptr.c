/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:02:36 by bchedru           #+#    #+#             */
/*   Updated: 2024/05/23 17:31:23 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned char *s)
{
	if (s == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (2 + ft_putnbr_base(*(size_t *)&s, "0123456789abcdef"));
}
