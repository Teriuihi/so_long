#include "headers/header_rename.h"
#include "mlx/mlx.h"

/**
 * Free's all memory that was allocated while the program was running
 *
 * @param	data	Struct containing all data for the program
 */
void	free_data(t_game_data *data)
{
	ft_lstclear(&data->file, ft_lstdelentry);
	if (data->file_array != NULL)
		free(data->file_array);
	if (data->mlx_window != NULL)
		mlx_destroy_window(data->mlx, data->mlx_window);
	free(data);
}
