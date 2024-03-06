/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:43:49 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/05 16:43:49 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

/*Custom error function that takes a string,
 displays it into stderr and exits on EXIT_FAILURE*/
int	ft_perror(char *error_message)
{
	write(2, error_message, ft_strlen(error_message));
	write(2, "\n", 1);
	exit(1);
}

char	*ft_strapp(char *s1, char *s2)
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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
