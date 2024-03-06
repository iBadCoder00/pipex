/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:23:01 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/12 16:24:02 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t size)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*src;

	dest = to;
	src = from;
	i = 0;
	if (!to)
		return (0);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (to);
}
