/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoreir <jumoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:04:33 by jumoreir          #+#    #+#             */
/*   Updated: 2026/07/22 16:04:33 by jumoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clean_stash(char *stash)
{
	int		i;
	int		start;
	char	*new_stash;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	start = i;
	while (stash[i] != '\0')
		i++;
	new_stash = ft_substr(stash, start, i - start);
	free(stash);
	return (new_stash);
}

static char	*fill_stash(int fd, char stash)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes;

	while (ft_strchr(stash, '\n') == 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	i;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (ft_substr(stash, 0, i));
}

char	*get_next_line(int fd)
{
	static char	*stash;
	size_t		i;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	while (stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
