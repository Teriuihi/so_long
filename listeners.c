#include "headers/header_rename.h"
#include "headers/draw.h"

/**
 * Updates new x/y and find the character for that tile
 *
 * @param	keycode	Code for the key that was pressed
 * @param	data	Data for the game
 *
 * @return	the character for the tile the player tried to move to.
 */
char	move_loc_type(int keycode, t_game_data *data)
{
	data->player.new_x = data->player.x;
	data->player.new_y = data->player.y;
	if (keycode == 13)
		data->player.new_y--;
	else if (keycode == 0)
		data->player.new_x--;
	else if (keycode == 1)
		data->player.new_y++;
	else if (keycode == 2)
		data->player.new_x++;
	else
	{
		free_data(data);
		ft_printf("Error\nMoved onto non existent tile.\n");
		exit(0);
	}
	return (data->file_array[data->player.new_y][data->player.new_x]);
}

void	update_pos(t_game_data *data)
{
	data->file_array[data->player.y][data->player.x] = '0';
	draw_sprite(data, data->player.y, data->player.x, '0');
	data->player.y = data->player.new_y;
	data->player.x = data->player.new_x;
	data->file_array[data->player.y][data->player.x] = 'P';
	draw_sprite(data, data->player.y, data->player.x, 'P');
	ft_printf("steps: %d\tcoins: %d/%d\n", data->player.steps,
		data->player.collected, data->collectibles);
}

void	move(int keycode, t_game_data *data)
{
	char	c;

	c = move_loc_type(keycode, data);
	if (c == '1')
		return ;
	if (c == 'E')
	{
		if (data->player.collected != data->collectibles)
			return ;
		else
		{
			data->player.steps++;
			update_pos(data);
			free_data(data);
			exit(0);
		}
	}
	if (c == 'C')
		data->player.collected++;
	data->player.steps++;
	update_pos(data);
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
	t_game_data	*data;

	data = ptr;
	if (keycode == 53)
	{
		free_data(data);
		exit(0);
	}
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		move(keycode, data);
	return (0);
}

int	window_close(void *param)
{
	t_game_data	*data;

	data = param;
	free_data(data);
	exit(0);
}
