#include "mlx/mlx.h"
#include "headers/so_long.h"

/**
 * Draws an image in the game window
 *
 * @param	data	Data for the game
 * @param	x		X pos in the window to draw at
 * @param	y		Y pos in the window to draw at
 * @param	file	File to draw
 */
void	draw_img(t_game_data *data, int x, int y, t_image *image)
{
	int		height;
	int		width;

	height = 32;
	width = 32;
	if (image->img == NULL)
		image->img = mlx_png_file_to_image(data->mlx, image->path, &width, &height);
	if (image->img == NULL)
	{
		ft_printf("Error\nUnable to load image at %s.\n", image->path);
		exit(0);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, image->img, x, y);
}

t_image	*get_player_frame_image(t_game_data *data, t_player *player)
{
	if (player->frame > 2)
		player->frame = 0;
	return (&data->images.player_frames[player->frame]);
}

void	draw_clear(t_game_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_window);
}

/**
 * Draws sprite for the character at the specified position in the game
 *
 * @param	data	Game data
 * @param	x		X pos in the grid to draw at
 * @param	y		Y pos in the grid to draw at
 * @param	c		Character to draw the sprite for
 */
void	draw_sprite(t_game_data *data, int y, int x, char c)
{
	y++;
	x++;
	y *= 32;
	x *= 32;
	if (c == '1')
		draw_img(data, x, y, &data->images.wall);
	else
		draw_img(data, x, y, &data->images.path);
	if (c == 'C')
		draw_img(data, x, y, &data->images.collectibles);
	else if (c == 'E')
		draw_img(data, x, y, &data->images.exit);
	else if (c == 'P')
		draw_img(data, x, y, get_player_frame_image(data, &data->player));
}
