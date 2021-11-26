#include <unistd.h>
#include "headers/header_rename.h"

void	tmp(void) //TODO REMOVE
{
	system("leaks so_long"); //TODO REMOVE
}

int	main(int len, char **args)
{
	t_game_data	*data;

	atexit(tmp); //TODO REMOVE
	data = ft_calloc(1, sizeof(t_game_data));
	if (data == NULL)
	{
		ft_printf("Error\nUnable to allocate memory for file data.\n");
		exit(0);
	}
	data->file = get_file(len, args);
	if (validate_file(data) || !store_file_as_2d_array(data))
	{
		free_data(data);
		exit(0);
	}
	start(data);
	return (0);
}
//TODO fix prefix and suffix checks in libft