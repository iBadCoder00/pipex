/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:58:11 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/12 17:02:43 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(int c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	get_trim_size(char const *s1, char const *set)
{
	size_t	i;
	size_t	length;
	size_t	temp;

	i = 0;
	length = 0;
	temp = 0;
	while (s1[i])
	{
		if (is_set(s1[i], set))
			temp++;
		else
		{
			length++;
			length += temp;
			temp = 0;
		}
		i++;
	}
	return (length);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	trim_size;
	char	*str;

	i = 0;
	if (!s1)
		return (0);
	while (is_set(s1[i], set))
		i++;
	trim_size = get_trim_size(&s1[i], set) + 1;
	str = (char *) malloc(trim_size);
	if (!str)
		return (0);
	k = i;
	j = 0;
	while (i < (k + trim_size) - 1)
	{
		str[j++] = s1[i++];
	}
	str[j] = 0;
	return (str);
}
