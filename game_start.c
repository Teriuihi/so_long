#include "headers/header_rename.h"
#include "mlx/mlx.h"

void	start(t_file_data *data)
{
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	if (mlx == NULL)
	{
		free_data(data);
		ft_printf("Error\nUnable to initiate mlx.\n");
		exit(0);
	}
	mlx_window = mlx_new_window(mlx,
			500,
			500,
			"TEST");
	mlx_loop(mlx_window);
}