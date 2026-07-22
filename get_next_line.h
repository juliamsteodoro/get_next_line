/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoreir <jumoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:04:54 by jumoreir          #+#    #+#             */
/*   Updated: 2026/07/22 16:04:54 by jumoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

	#ifndef BUFFER_SIZE
	# define BUFFER_SIZE 3
	#endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *src);
size_t	ft_strlcpy( char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

#endif