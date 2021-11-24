#include "header_rename.h"
#include "mlx/mlx.h"

void	start(t_file_data *data)
{
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx,
			(data->row_length) * 100,
			(data->rows) * 100,
			"TEST");
	mlx_loop(mlx_window);
}
