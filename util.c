/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 17:57:15 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 17:57:15 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"
#include "mlx/mlx.h"

/**
 * Free's all memory that was allocated while the program was running
 *
 * @param	data	Struct containing all data for the program
 */
void	free_data(t_game_data *data)
{
	ft_lstclear(&data->file.linked_file, ft_lstdelentry);
	if (data->file.file_array != NULL)
		free(data->file.file_array);
	if (data->mlx_window != NULL)
		mlx_destroy_window(data->mlx, data->mlx_window);
	free(data);
}
