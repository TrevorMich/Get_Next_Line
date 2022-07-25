/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioduwole <ioduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:35:12 by ioduwole          #+#    #+#             */
/*   Updated: 2022/07/25 10:56:40 by ioduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*find_line(char *finder)
{
	char	*found;

	found = ft_strchr(finder, '\n');
	if (!found)
	{
		free(finder);
		return (0);
	}
	if (*(found + 1))
		found = ft_strdup(found + 1);
	else
		found = NULL;
	free(finder);
	return (found);
}

char	*get_next_line(int fd)
{
	static char				*tstring[8000];
	char					*dest;
	char					line[BUFFER_SIZE + 1];
	int						size;

	size = read(fd, line, BUFFER_SIZE);
	if (size == -1)
		return (NULL);
	line[size] = '\0';
	while (size > 0)
	{
		if (!tstring[fd])
			tstring[fd] = ft_strdup(line);
		else
			tstring[fd] = ft_strjoin(tstring[fd], line);
		if (ft_strchr(line, '\n'))
			break ;
		size = read(fd, line, BUFFER_SIZE);
		line[size] = '\0';
	}
	dest = ft_substr(tstring[fd], 0, ft_strchr(tstring[fd], '\n')
			- tstring[fd] + 1);
	tstring[fd] = find_line(tstring[fd]);
	return (dest);
}
