#include <unistd.h>
#include <fcntl.h>
#include "header_rename.h"

t_list	*get_file(int len, char **args)
{
	int		fd;
	t_list	*file;

	if (len != 2)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	fd = open(args[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	file = load_file(fd);
	if (file == NULL)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	return (file);
}

int	main(int len, char **args)
{
	t_list *file;

	file = get_file(len, args);
	return (0);
}
