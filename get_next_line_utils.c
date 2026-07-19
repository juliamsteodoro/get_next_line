/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:58:17 by marvin            #+#    #+#             */
/*   Updated: 2026/07/08 13:58:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy( char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	if (!dst || !src)
		return (0);
	len = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	d;
	size_t	s;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size <= dlen)
		return (size + slen);
	d = dlen;
	s = 0;
	while (src[s] != '\0' && d + 1 < size)
	{
		dst[d] = src[s];
		d++;
		s++;
	}
	dst[d] = '\0';
	return (dlen + slen);
}

size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char *ft_strchr(const char *s, int c)
{
    size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (len + 1));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, len + 1);
	ft_strlcat(s3, s2, len + 1);
	return (s3);
}
void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
		len = 0;
	else if (slen - start < len)
		len = slen - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;
	size_t			i;

	ptr_d = (unsigned char *)dst;
	ptr_s = (unsigned char *)src;
	i = 0;
	if (ptr_d > ptr_s)
	{
		while (n > 0)
		{
			n--;
			ptr_d[n] = ptr_s[n];
		}
	}
	else
	{
		while (i < n)
		{
			ptr_d[i] = ptr_s[i];
			i++;
		}
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, len + 1);
	return (copy);
}