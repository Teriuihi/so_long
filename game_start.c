#include "headers/so_long.h"
#include "mlx/mlx.h"
#include "headers/draw.h"
#include "headers/events.h"

void	draw(t_game_data *data)
{
	char	**file_array;
	int		y;
	int		x;

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
}

void	setup_listeners(t_game_data *data)
{
	mlx_key_hook(data->mlx_window, key_click, data);
	mlx_hook(data->mlx_window, 17, 0L, window_close, data);
}

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

void	run_game(t_game_data *data)
{
	pthread_t	thread_id;

	data->game.running = 1;
	pthread_create(&thread_id, NULL, animation_start, data);
	//Allow this thread to be locked so it can only execute after we finish moving the player
	data->animation = thread_id;
	mlx_loop(data->mlx);
}

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
	draw(data);
	find_player(data);
	setup_listeners(data);
	run_game(data);
}
