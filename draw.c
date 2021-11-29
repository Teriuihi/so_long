#include "mlx/mlx.h"
#include "headers/header_rename.h"

/**
 * Draws an image in the game window
 *
 * @param	data	Data for the game
 * @param	x		X pos in the window to draw at
 * @param	y		Y pos in the window to draw at
 * @param	file	File to draw
 */
void	draw_img(t_game_data *data, int x, int y, char *file)
{
	int		height;
	int		width;
	void	*img;

	height = 32;
	width = 32;
	img = mlx_png_file_to_image(data->mlx, file, &width, &height);
	if (img == NULL)
	{
		ft_printf("Error\nUnable to load image at %s.\n", *file);
		exit(0);
	}
	mlx_put_image_to_window(data->mlx, data->mlx_window, img, x, y);
}

char	*get_player_frame_image(t_player *player)
{
	if (player->frame == 0)
		return "./images/player0.png";
	if (player->frame == 1)
		return "./images/player0.png";
	if (player->frame == 2)
		return "./images/player0.png";
	if (player->frame == 3)
		return "./images/player0.png";
	if (player->frame == 4)
		return "./images/player0.png";
	player->frame = 0;
	return "./images/player0.png";
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
		draw_img(data, x, y, "./images/wall.png");
	else
		draw_img(data, x, y, "./images/path.png");
	if (c == 'C')
		draw_img(data, x, y, "./images/collectibles.png");
	else if (c == 'E')
		draw_img(data, x, y, "./images/exit.png");
	else if (c == 'P')
		draw_img(data, x, y, get_player_frame_image(&data->player));
}
