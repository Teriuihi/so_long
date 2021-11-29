#include "headers/header_rename.h"

/**
 * Listens for key clicks and runs functions based on those clicks
 *
 * 	exc = 53
 * 	w = 13
 * 	a = 0
 * 	s = 1
 * 	d = 2
 *
 * @param	keycode	Key code the user clicked
 * @param	ptr		Pointer to data for the game
 *
 * @return	0
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

/**
 * Listens if the game window closes and if so ends the game
 *
 * @param	param	Pointer to data for the game
 *
 * @return	0
 */
int	window_close(void *param)
{
	t_game_data	*data;

	data = param;
	free_data(data);
	exit(0);
}
