/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:34:38 by acolonne          #+#    #+#             */
/*   Updated: 2025/02/06 17:28:59 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c)
			count++;
	}
	return (count);
}

static int	count_letter(char const *s, char c, int i)
{
	int	letter;

	letter = 0;
	while (s[i] != c && s[i])
	{
		i++;
		letter++;
	}
	return (letter);
}

char	**free_split(char **split, int a)
{
	int	i;

	i = 0;
	while (i < a)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

static char	**assign_split(char **split, char const *s, char c, int words)
{
	int	a;
	int	b;
	int	i;
	int	size;

	a = 0;
	i = 0;
	while (s[i] && a < words)
	{
		b = 0;
		while (s[i] == c && s[i])
			i++;
		size = count_letter(s, c, i);
		split[a] = malloc(sizeof(char) * size + 1);
		if (!split[a])
			return (free_split(split, a));
		while (b < size && s[i])
			split[a][b++] = s[i++];
		split[a++][b] = '\0';
	}
	split[a] = 0;
	return (split);
}

char	**ft_split(char const *s, char c, int *split_len)
{
	int		words;
	char	**split;

	if (!s)
		return (0);
	words = count_words(s, c);
	split = malloc((sizeof(char *) * (words + 1)));
	if (!split)
		return (0);
	*split_len = words;
	split = assign_split(split, s, c, words);
	return (split);
}
