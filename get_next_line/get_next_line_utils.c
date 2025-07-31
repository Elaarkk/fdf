/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:49:15 by acolonne          #+#    #+#             */
/*   Updated: 2025/02/03 18:49:42 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)&s[i + 1]);
		i++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(len + 1);
	if (!dest)
		return (0);
	while (s1 && s1[j])
		dest[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*t;

	i = 0;
	t = s;
	while (i < n)
	{
		t[i] = '\0';
		i++;
	}
	return ;
}
