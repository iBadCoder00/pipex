/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:43:19 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/12 16:49:24 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*new_str;

	if (!s)
		return (0);
	i = 0;
	new_str = malloc(ft_strlen(s) + 1);
	if (!new_str)
		return (0);
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
