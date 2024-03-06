/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:56:32 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/12 16:57:59 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		cur;
	char	*ret;

	cur = 0;
	ret = 0;
	while (s[cur])
	{
		if (s[cur] == (unsigned char)c)
			ret = (char *)(s + cur);
		cur++;
	}
	if (s[cur] == (unsigned char)c)
		ret = (char *)(s + cur);
	return (ret);
}
