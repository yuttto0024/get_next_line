/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:46:53 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/07 11:39:34 by yuonishi         ###   ########.fr       */
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

char	*ft_realloc_gnl(char *stash, size_t old_len, size_t new_size)
{
	char	*new_stash;
	size_t	i;

	new_stash = (char *)malloc(sizeof(char) * new_size);
	if (!new_stash)
		return (free(stash), NULL);
	i = 0;
	if (stash)
	{
		while (i < old_len)
		{
			new_stash[i] = stash[i];
			i++;
		}
	}
	new_stash[i] = '\0';
	return (free(stash), new_stash);
}

char	*ft_strjoin_gnl(char *stash, char *buf)
{
	char	*new_stash;
	size_t	stash_len;
	size_t	buf_len;
	size_t	i;

	stash_len = 0;
	buf_len = 0;
	if (stash)
		stash_len = ft_strlen(stash);
	if (buf)
		buf_len = ft_strlen(buf);
	new_stash = ft_realloc_gnl(stash, stash_len, stash_len + buf_len + 1);
	if (!new_stash)
		return (NULL);
	i = 0;
	while (i < buf_len)
	{
		new_stash[stash_len + i] = buf[i];
		i++;
	}
	new_stash[stash_len + i] = '\0';
	return (new_stash);
}
