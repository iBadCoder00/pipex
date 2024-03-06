/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:31:39 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/12 17:32:18 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	modulo;

	modulo = n % 10;
	n /= 10;
	if (n < 0 || modulo < 0)
	{
		ft_putchar_fd('-', fd);
		modulo *= -1;
		n *= -1;
	}
	if (n > 0)
	{
		ft_putnbr_fd(n, fd);
		ft_putchar_fd(modulo + '0', fd);
	}
	else
	{
		ft_putchar_fd(modulo + '0', fd);
	}
}
