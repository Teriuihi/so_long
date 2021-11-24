#include "mlx/mlx.h"
#include "headers/header_rename.h"

void	draw_img(t_file_data *data, int x, int y, char *file)
{
	int		height;
	int		width;
	void	*img;

	height = 32;
	width = 32;
	img = mlx_png_file_to_image(data->mlx, file, &width, &height);
	if (img == NULL)
	{
		ft_printf("Error\nUnable to load wall.\n");
		exit(0);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, img, x, y);
}

void	draw_sprite(t_file_data *data, int x, int y, char c)
{
	if (c == '1')
		draw_img(data, x, y, "./images/wall.png");
	else
		draw_img(data, x, y, "./images/path.png");
	if (c == 'C')
		draw_img(data, x, y, "./images/collectibles.png");
	else if (c == 'E')
		draw_img(data, x, y, "./images/exit.png");
	else if (c == 'P')
		draw_img(data, x, y, "./images/player.png");
}