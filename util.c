#include "headers/header_rename.h"
#include "mlx/mlx.h"

void	free_data(t_game_data *data)
{
	ft_lstclear(&data->file, ft_lstdelentry);
	if (data->file_array != NULL)
		free(data->file_array);
	if (data->mlx_window != NULL)
		mlx_destroy_window(data->mlx, data->mlx_window);
	free(data);
}
