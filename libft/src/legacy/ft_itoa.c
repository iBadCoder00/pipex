/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:06:50 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/12 16:10:03 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_length(int n)
{
	int	length;

	length = 0;
	if (!n || n < 0)
		length++;
	while (n != 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;

	length = num_length(n);
	str = (char *) malloc(length + 1);
	if (!str)
		return (0);
	str[length] = 0;
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
		str[0] = '-';
	while (length > 0)
	{
		if (n < 0)
			str[length - 1] = -(n % 10) + '0';
		else if (n > 0)
			str[length - 1] = (n % 10) + '0';
		n /= 10;
		length--;
	}
	return (str);
}
