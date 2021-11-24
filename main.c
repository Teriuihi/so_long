#include <unistd.h>
#include "header_rename.h"

void	tmp(void) //TODO REMOVE
{
	system("leaks so_long"); //TODO REMOVE
}

int	main(int len, char **args)
{
	t_file_data *data;

	data = ft_calloc(1, sizeof(t_file_data));
	if (data == NULL)
	{
		write(1, "Error\nUnable to allocate memory for file data.\n", 47);
		exit(0);
	}
	data->file = get_file(len, args);
	if (!validate_file(data))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	ft_lstclear(&(data->file), ft_lstdelentry);
	free(data);
	atexit(tmp); //TODO REMOVE
	return (0);
}
