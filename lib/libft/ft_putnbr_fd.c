/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:44:05 by bchedru           #+#    #+#             */
/*   Updated: 2023/10/26 11:37:16 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putdigit_fd(unsigned long int n, int fd)
{
	if (n > 9)
		ft_putdigit_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	longn;

	longn = (long int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		longn = -longn;
	}
	ft_putdigit_fd(longn, fd);
}
