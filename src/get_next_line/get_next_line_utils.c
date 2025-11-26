/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:46:14 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/06/23 12:43:26 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	copy_strs(char *joined, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
	{
		free(s1);
		return (NULL);
	}
	copy_strs(joined, s1, s2);
	free(s1);
	return (joined);
}
