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
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *linha;

    // Abre um arquivo chamado teste.txt em modo de leitura
    fd = open("teste.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Erro ao abrir o arquivo! Crie um arquivo 'teste.txt'.\n");
        return (1);
    }

    // Lê linha por linha até o get_next_line retornar NULL (fim do arquivo)
    while ((linha = get_next_line(fd)) != NULL)
    {
        printf("%s", linha);
        free(linha); // Muito importante liberar a linha impressa!
    }

    close(fd);
    return (0);
}