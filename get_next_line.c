/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 17:20:41 by marvin            #+#    #+#             */
/*   Updated: 2026/07/02 17:20:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char     *clean_stash(char *stash)
{
    int i;
    int start;
    char *new_stash;
    i = 0;
    while(stash[i] != '\0' && stash[i] != '\n')
        i++;
    if(stash[i] == '\n')
        i++;
    if(stash[i] == '\0')
    {
        free(stash);
        return (NULL);
    }
    start = i;
    while(stash[i] != '\0')
        i++;
    new_stash = ft_substr(stash, start, i - start);
    free(stash);
    return(new_stash);
}

char    *get_next_line(int fd)
{
    static char *stash;
    char        buffer[BUFFER_SIZE + 1];
    ssize_t       bytes;
    size_t      i;
    char    *line;

    if(fd < 0 || BUFFER_SIZE <= 0) 
        return (NULL);

    if(!stash)
    {
        stash = malloc(1);
        if (!stash)
            return (NULL);
        stash[0] = '\0';
    }
    while(ft_strchr(stash, '\n') == 0)
    {
        bytes = read(fd,buffer, BUFFER_SIZE);
        if(bytes < 0)
        {
            free(stash);
            stash = NULL;
            return(NULL);
        }
        if(bytes == 0)
            break;
        buffer[bytes] = '\0';
        stash = ft_strjoin(stash, buffer);
    }
    if(stash[0] == '\0')
    {
        free(stash);
        stash = NULL;
        return(NULL);
    }
    i = 0;
    while(stash[i] != '\0' && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    line = ft_substr(stash, 0, i);
    stash = clean_stash(stash);
    return(line);
}
