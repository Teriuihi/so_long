#include "headers/header_rename.h"

void	free_data(t_file_data *data)
{
	ft_lstclear(&data->file, ft_lstdelentry);
	if (data->file_array != NULL)
		free(data->file_array);
	free(data);
}