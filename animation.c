#include "headers/header_rename.h"
#include "headers/draw.h"
#include <unistd.h>
#include <pthread.h>

void	*animation_start(void *ptr)
{
	t_game_data	*data;

	data = ptr;
	while (data->game.running)
	{
		while (data->player.processing)
			usleep(5);
		if (data->player.moved)
		{
			data->player.moved = 0;
			draw_sprite(data, data->player.old.y, data->player.old.x, '0');
		}
		draw_sprite(data, data->player.cur.y, data->player.cur.x, 'P');
		if (data->player.frame == 5)
			data->player.frame = 0;
		else
			data->player.frame++;
		usleep(1000);
	}
	return (NULL);
}
