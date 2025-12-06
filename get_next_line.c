/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:37:07 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/06 13:39:29 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_add_to_stash(int fd, char *stash)
{
	char	*buf;
	int		bytes_readed;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (free(stash), NULL);
	bytes_readed = 1;
	while (!ft_strchr(stash, '\n') && bytes_readed > 0)
	{
		bytes_readed = read(fd, buf, BUFFER_SIZE);
		if (bytes_readed == -1)
			return (free(buf), free(stash), NULL);
		if (bytes_readed == 0)
			break ;
		buf[bytes_readed] = '\0';
		stash = ft_strjoin_gnl(stash, buf);
		if (stash == NULL)
			return (free(buf), NULL);
	}
	return (free(buf), stash);
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
		return (free(stash), NULL);
	new_stash = ft_strdup_gnl(&stash[i + 1]);
	return (free(stash), new_stash);
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
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = update_stash(stash);
	return (line);
}
