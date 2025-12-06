/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:14:54 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/06 13:28:25 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_realloc_stash(char *ptr, size_t new_size)
{
	char	*new_ptr;
	size_t	i;

	new_ptr = (char *)malloc(sizeof(char) * new_size);
	if (new_ptr == NULL)
		return (free(ptr), NULL);
	i = 0;
	if (ptr != NULL)
	{
		while (ptr[i])
		{
			new_ptr[i] = ptr[i];
			i++;
		}
		free(ptr);
	}
	new_ptr[i] = '\0';
	return (new_ptr);
}

char	*ft_strjoin_gnl(char *stash, char *buf)
{
	char	*new_stash;
	size_t	len_stash;
	size_t	len_buf;
	size_t	i;
	size_t	j;

	len_stash = 0;
	if (stash)
		len_stash = ft_strlen(stash);
	len_buf = ft_strlen(buf);
	new_stash = ft_realloc_stash(stash, len_stash + len_buf + 1);
	if (new_stash == NULL)
		return (NULL);
	i = len_stash;
	j = 0;
	while (buf[j])
		new_stash[i++] = buf[j++];
	new_stash[i] = '\0';
	return (new_stash);
}

char	*ft_strdup_gnl(const char *src)
{
	char	*dest;
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
