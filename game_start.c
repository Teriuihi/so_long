/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_start.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 17:57:28 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 17:57:28 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"
#include "mlx/mlx.h"
#include "headers/events.h"

/**
 * Draws the map onto the screen based on the map data
 *
 * @param	data	All game data
 */
void	draw_game(t_game_data *data)
{
	char	**file_array;
	int		y;
	int		x;

	draw_clear(data);
	file_array = data->file.file_array;
	y = 0;
	while (y < data->file.rows)
	{
		x = 0;
		while (x < data->file.row_length)
		{
			draw_sprite(data, y, x, file_array[y][x]);
			x++;
		}
		y++;
	}
	draw_steps(data);
}

/**
 * Start all listeners for the game
 * 	mlx_key_hook listens to any keypress
 * 	mlx_hook listens if the user closes the window with the red x
 *
 * @param	data	All game data
 */
void	setup_listeners(t_game_data *data)
{
	mlx_key_hook(data->mlx_window, key_click, data);
	mlx_hook(data->mlx_window, 17, 0L, window_close, data);
}

/**
 * Find the player in the map and store their position
 *
 * @param	data	All game data
 */
void	find_player(t_game_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->file.rows)
	{
		x = 0;
		while (x < data->file.row_length)
		{
			if (data->file.file_array[y][x] == 'P')
			{
				data->player.cur.x = x;
				data->player.cur.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

/**
 * Prepare the game to be started and then start it
 * 	Start mlx
 * 	Open mlx window
 * 	Draw game, find player, start listeners
 * 	Start game loop
 *
 * @param	data	All game data
 */
void	start(t_game_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		free_data(data);
		ft_printf("Error\nUnable to initiate mlx.\n");
		exit(0);
	}
	data->mlx_window = mlx_new_window(data->mlx,
			(data->file.row_length + 2) * 32,
			(data->file.rows + 2) * 32,
			"so_long");
	if (data->mlx_window == NULL)
	{
		free_data(data);
		ft_printf("Error\nUnable to initiate window.\n");
		exit(0);
	}
	draw_game(data);
	find_player(data);
	setup_listeners(data);
	mlx_loop(data->mlx);
}
