#include "headers/header_rename.h"

void	move(int keycode, t_file_data *data)
{
//	if (valid_move(pos, direction))
//	{
//		update_pos(); //TODO update internal map and screen
//		data->steps++;
//	}
}

/**
 * Handles key clicks
 *
 * @param	keycode
 * @param	ptr
 *
 * @return
 * exc = 53
 * w = 13
 * a = 0
 * s = 1
 * d = 2
 */
int	key_click(int keycode, void *ptr)
{
	t_file_data	*data;

	data = ptr;
	if (keycode == 53)
	{
		free_data(data);
		exit(0);
	}
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		move(keycode, data);
	ft_printf("Nice %d:%d\n", keycode, data->player);
	return (0);
}