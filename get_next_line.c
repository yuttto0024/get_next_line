/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 09:12:32 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/07 12:02:46 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_stash(int fd, char *stash)
{
	char	*buf;
	int		r;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free(stash), NULL);
	r = 1;
	while (!ft_strchr(stash, '\n') && r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (free(buf), free(stash), NULL);
		if (r == 0)
			break ;
		buf[r] = '\0';
		stash = ft_strjoin_gnl(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	return (free(buf), stash);
}

static char	*extract_line(char *stash)
{
	char	*line;
	size_t	i;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_stash(char *stash)
{
	char	*new_stash;
	size_t	i;	// if (stash[0] == '\0')
	// 	(free(stash));
	size_t	j;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = (char *)malloc(sizeof(char) * ((ft_strlen(stash) - i) + 1));
	if (!new_stash)
		return (free(stash), NULL);
	j = 0;
	while (stash[i])
	{
		new_stash[j] = stash[i + 1];
		i++;
		j++;
	}
	new_stash[j] = '\0';
	return (free(stash), new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = update_stash(stash);
	// if (stash[0] == '\0')
	// 	(free(stash));
	return (line);
}
