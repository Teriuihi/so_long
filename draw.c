#include "mlx/mlx.h"
#include "headers/header_rename.h"

void	draw_img(t_file_data *data, int x, int y)
{
	int		height;
	int		width;
	void	*img;

	height = 32;
	width = 32;
	img = mlx_png_file_to_image(data->mlx, "./images/wall.png", &width, &height);
	if (img == NULL)
	{
		ft_printf("Error\nUnable to load wall.\n");
		exit(0);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, img, x, y);
}

void	draw_sprite(t_file_data *data, int x, int y, char c)
{

}