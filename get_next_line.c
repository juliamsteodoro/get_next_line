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

char    *get_next_line(int fd)
{
    static char *stash;
    char buffer[BUFFER_SIZE + 1];

    if(fd < 0 || BUFFER_SIZE == 0)
        return (NULL);
    while(ft_strchr(stash, '\n'))
}

lê mais dados se necessário
    encontra '\n'
    separa linha
    atualiza stash
    retorna linha