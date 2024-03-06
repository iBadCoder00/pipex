/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:50:03 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/12 16:51:43 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *to, const char *from, size_t size)
{
	size_t	l_dest;

	l_dest = ft_strlen(to);
	if (size <= ft_strlen(to))
		return (ft_strlen(from) + size);
	while (l_dest < size - 1 && *from)
	{
		to[l_dest++] = *from;
		from++;
	}
	to[l_dest] = 0;
	return (l_dest + ft_strlen(from));
}
