/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:02:09 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/12 16:02:42 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t eltsize)
{
	void	*memory;

	memory = (void *) malloc(count * eltsize);
	if (!memory)
		return (0);
	ft_memset(memory, 0, count * eltsize);
	return (memory);
}
