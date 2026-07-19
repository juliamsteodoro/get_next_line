/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:19:14 by marvin            #+#    #+#             */
/*   Updated: 2026/07/07 18:19:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>

    #ifndef BUFFER_SIZE
    #define BUFFER_SIZE 3
    #endif

char    *get_next_line(int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *src);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy( char *dst, const char *src, size_t size);
void	ft_putchar_fd(char c, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s);


#endif