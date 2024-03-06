/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:01:15 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/12 16:01:20 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *block, size_t size)
{
	size_t	i;
	char	*bytes;

	i = 0;
	bytes = (char *) block;
	while (i < size)
	{
		*bytes = 0;
		bytes++;
		i++;
	}
}
