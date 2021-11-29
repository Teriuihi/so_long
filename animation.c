#include "headers/header_rename.h"
#include "headers/draw.h"
#include <unistd.h>

void	*animation_start(void *ptr)
{
	t_game_data *data;

	data = ptr;
	while (data->game.running)
	{
		draw_sprite(data, data->player.y, data->player.x, 'P');
		if (data->player.frame == 5)
			data->player.frame = 0;
		else
			data->player.frame++;
		usleep(5000);
	}
	return (NULL);
}