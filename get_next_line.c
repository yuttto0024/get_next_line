#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	char	buf[BUFFER_SIZE + 1];
	int		bytes_read;

	fd = open("test01.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error1\n", 6);
		return (0);
	}
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		if (strchr(buf, '\n'))

	}
	close(fd);
	return (0);
}