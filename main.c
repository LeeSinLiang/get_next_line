#include "get_next_line.h"
#include <stdio.h>

bool	gnl(int fd)
{
	char	*buffer;

	buffer = get_next_line(fd);
	if (buffer == NULL)
		return (true);
	printf("%s", buffer);
	free(buffer);
	return (false);
}

int	main(void)
{
	int	n;
	int	fd;

	n = 0;
	fd = open("get_next_line.c", O_RDWR);
	while (gnl(fd) == false)
		n++;
	printf("\n--------------END OF LINE READING--------------\n");
	printf("\nN Lines: %d\n", n);
	return (0);
}
