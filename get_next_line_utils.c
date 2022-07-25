/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:33:23 by ioduwole          #+#    #+#             */
/*   Updated: 2022/07/24 00:39:51 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char			*dup;
	int				i;
	int				len;

	i = 0;
	len = ft_strlen(str) + 1;
	dup = malloc(len * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return ((char *)(str + i));
		}
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dest;
	size_t		i;
	size_t		length;

	if (s == NULL)
		return (NULL);
	i = 0;
	length = ft_strlen(s);
	if (start >= length || !s)
		len = 0;
	else if (length < (start + len))
		len = length - start;
	dest = malloc(len + 1);
	if (dest != NULL)
	{
		while (i < len && s[i])
		{
			dest[i] = s[start + i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char			*dest;
	size_t			len;
	size_t			i;
	size_t			j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	while (s1[++i] != '\0')
		dest[i] = s1[i];
	while (s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	free(s1);
	return (dest);
}
