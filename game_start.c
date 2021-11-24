#include "headers/header_rename.h"
#include "mlx/mlx.h"
#include "headers/draw.h"

void	draw(t_file_data *data) //TODO maybe change file to a 2d array?
{
	t_list	*file;
	char	*row;
	int		i;
	int		j;

	i = 1;
	file = data->file;
	while (file)
	{
		j = 1;
		row = file->content;
		while (*row && *row != '\n')
		{
			draw_sprite(data, j * 32, i * 32, *row);
			row++;
			j++;
		}
		file = file->next;
		i++;
	}
}

void	start(t_file_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		free_data(data);
		ft_printf("Error\nUnable to initiate mlx.\n");
		exit(0);
	}
	data->mlx_window = mlx_new_window(data->mlx,
			500,
			500,
			"TEST");
	if (data->mlx_window == NULL)
	{
		free_data(data);
		ft_printf("Error\nUnable to initiate window.\n");
		exit(0);
	}
	draw(data);
	mlx_loop(data->mlx);
}