/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:29:34 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/25 17:29:34 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strapp_g(char *s1, char *s2)
{
	size_t	i;
	char	*new_str;

	if (!s1)
	{
		s1 = malloc (1);
		*s1 = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	if (!new_str)
		return (NULL);
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2 && *s2)
		new_str[i++] = *s2++;
	new_str[i] = 0;
	free(s1);
	return (new_str);
}

int	line_length(char *s)
{
	int	length;

	length = 0;
	if (!s)
		return (length);
	while (s[length] != '\n' && s[length])
		length++;
	if (s[length] == '\n')
		length++;
	return (length);
}
