#include "headers/header_rename.h"
#include "mlx/mlx.h"
#include "headers/draw.h"
#include "headers/events.h"

void	draw(t_game_data *data)
{
	char	**file_array;
	int		y;
	int		x;

	file_array = data->file_array;
	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->row_length)
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
	while (y < data->rows)
	{
		x = 0;
		while (x < data->row_length)
		{
			if (data->file_array[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
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
			(data->row_length + 2) * 32,
			(data->rows + 2) * 32,
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
	mlx_loop(data->mlx);
}
