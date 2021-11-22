#include <unistd.h>
#include <fcntl.h>
#include "header_rename.h"

int	main(int len, char **args)
{
	int	fd;

	if (len != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	fd = open(args[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	load_file(fd);
	return (0);
}
