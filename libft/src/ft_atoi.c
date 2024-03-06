/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:58:51 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/12 16:00:12 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *string)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	if (!string)
		return (0);
	while ((*string >= 9 && *string <= 13) || *string == 32)
		string++;
	if (*string == '-' || *string == '+')
	{
		if (*string == '-')
			sign *= -1;
		string++;
	}
	while (*string >= '0' && *string <= '9')
	{
		number = number * 10 + *string - '0';
		string++;
	}
	return (number * sign);
}
