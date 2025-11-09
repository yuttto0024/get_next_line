#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	buf[10];

	fd = open("test01.txt", O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error1\n", 6);
		return (0);
	}
	read(fd, buf, 10);
	printf("%s", buf);
	close(fd);
	return (0);
}