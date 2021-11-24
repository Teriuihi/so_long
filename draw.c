#include "mlx/mlx.h"

void	draw_wall(void *mlx, int x, int y)
{
	mlx_png_file_to_image(mlx, "images/wall.jpeg", &x, &y);
}