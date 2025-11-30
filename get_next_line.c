/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:37:07 by yuonishi          #+#    #+#             */
/*   Updated: 2025/11/30 19:50:30 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_add_to_stash(int fd, char *stash)
{
	char	*buf;
	int		bytes_readed;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	bytes_readed = 1;
	while (ft_strchr(stash, '\n') == NULL && bytes_readed != 0)
	{
		bytes_readed = read(fd, buf, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[bytes_readed] = '\0';
		stash = ft_strjoin_gnl(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*extract_line_from_stash(char *stash)
{
	char	*line;
	size_t	i;

	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_stash(char *stash)
{
	size_t	i;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup_gnl(&stash[i + 1]);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_add_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line_from_stash(stash);
	stash = update_stash(stash);
	return (line);
}