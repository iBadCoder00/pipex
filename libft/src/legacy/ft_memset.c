/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:26:15 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/12 16:27:37 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *block, int c, size_t size)
{
	size_t	i;
	char	*bytes;

	i = 0;
	bytes = (char *) block;
	while (i < size)
	{
		*bytes = (unsigned char) c;
		bytes++;
		i++;
	}
	return (block);
}
