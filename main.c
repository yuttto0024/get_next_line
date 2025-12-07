/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuonishi <yuonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:33:02 by yuonishi          #+#    #+#             */
/*   Updated: 2025/12/07 11:42:18 by yuonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open("1char.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error1\n");
		return (1);
	}
	line_count = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("[%d]:%s", line_count, line);
		free(line);
		line_count++;
	}
	close(fd);
	return (0);
}
