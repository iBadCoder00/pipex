/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:19:54 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/12 16:21:33 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *block, int c, size_t size)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) block;
	ch = (unsigned char) c;
	if (!block)
		return (0);
	while (i < size)
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	return (0);
}
