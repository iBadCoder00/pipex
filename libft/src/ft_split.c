/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:35:30 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/12 16:41:35 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == 0))
			words++;
		i++;
	}
	return (words);
}

static size_t	wordlen(char const*s, char c)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*s == c)
		s++;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*get_word(char const*s, char c)
{
	size_t	len;
	size_t	n;
	char	*word;

	while (*s == c)
		s++;
	n = 0;
	len = wordlen(s, c);
	word = malloc(len + 1);
	if (!word)
		return (0);
	while (n < len)
	{
		word[n] = s[n];
		n++;
	}
	word[n] = 0;
	return (word);
}

static void	*delete(char **tab, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(tab[j++]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!(tab))
		return (delete(tab, 0));
	while (*s)
	{
		if ((*s != c && *(s - 1) == c) || (i == 0 && *s != c))
		{
			tab[i] = get_word(s, c);
			if (!tab[i])
				return (delete(tab, i));
			s += (wordlen(s, c));
			i++;
		}
		else
			s++;
	}
	tab[i] = 0;
	return (tab);
}
