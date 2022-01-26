/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_move.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 17:57:27 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 17:57:27 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

/**
 * Updates new x/y and find the character for that tile
 *
 * @param	keycode	Code for the key that was pressed
 * @param	data	Data for the game
 *
 * @return	the character for the tile the player tried to move to.
 */
char	move_loc_type(int keycode, t_game_data *data, t_pos *pos)
{
	pos->x = data->player.cur.x;
	pos->y = data->player.cur.y;
	if (keycode == 13)
		pos->y--;
	else if (keycode == 0)
		pos->x--;
	else if (keycode == 1)
		pos->y++;
	else if (keycode == 2)
		pos->x++;
	else
	{
		free_data(data);
		ft_printf("Error\nMoved onto non existent tile.\n");
		exit(0);
	}
	return (data->file.file_array[pos->y][pos->x]);
}

/**
 * Updated the offset for drawing the game
 * Offset every 20 tiles on x and every 10 on y
 * 	but for going right double this so it doesn't move back and forth as often
 *
 * @param	data	Game data
 */
void	update_offset(t_game_data *data)
{
	int	x;
	int	y;
	int	x_diff;
	int	y_diff;

	x = data->player.cur.x / 10;
	y = data->player.cur.y / 10;
	x_diff = x - data->game.off_set_x;
	y_diff = y - data->game.off_set_y;
	if (x_diff > 1 || x_diff < 0 || y_diff > 1 || y_diff < 0)
	{
		data->game.off_set_x = x;
		data->game.off_set_y = y;
		draw_game(data);
	}
}

/**
 * Updates the player location on the screen and in the internal map
 *
 * @param	data	Data for the game
 */
void	update_pos(t_game_data *data, t_pos *pos)
{
	data->file.file_array[data->player.cur.y][data->player.cur.x] = '0';
	data->file.file_array[pos->y][pos->x] = 'P';
	data->player.old.y = data->player.cur.y;
	data->player.old.x = data->player.cur.x;
	data->player.cur.y = pos->y;
	data->player.cur.x = pos->x;
	data->player.frame++;
	draw_sprite(data, data->player.old.y - (data->game.off_set_y * 10),
		data->player.old.x - (data->game.off_set_x * 10), '0');
	update_offset(data);
	draw_sprite(data, data->player.cur.y - (data->game.off_set_y * 10),
		data->player.cur.x - (data->game.off_set_x * 10), 'P');
	ft_printf("steps: %d\n", data->player.steps);
	draw_steps(data);
}

/**
 * Checks if the movement is valid and if it is moves the player and updates
 * 	the game data where needed
 *
 * @param	keycode	The code of the key that was pressed by the user
 * @param	data	Data for the game
 */
void	move(int keycode, t_game_data *data)
{
	char	c;
	t_pos	pos;

	c = move_loc_type(keycode, data, &pos);
	if (c == '1')
		return ;
	if (c == 'E')
	{
		if (data->player.collected != data->game.collectibles)
			return ;
		else
		{
			data->player.steps++;
			update_pos(data, &pos);
			free_data(data);
			exit(0);
		}
	}
	if (c == 'C')
		data->player.collected++;
	data->player.steps++;
	update_pos(data, &pos);
}
