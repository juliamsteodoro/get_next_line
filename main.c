/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:19:44 by marvin            #+#    #+#             */
/*   Updated: 2026/06/24 10:19:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main (void)
{
    int fd;
    char *line;

    fd = open("teste.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    line = ft_get_next_line(fd);
    while (line != NULL)
    {
        ft_putstr(line);
        free (line);
        line = ft_get_next_line(fd);
    }
    close (fd);
    return (0);
}
