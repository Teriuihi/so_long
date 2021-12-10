/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 17:58:19 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 17:58:19 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <pthread.h>
# include "../libft/libft.h"

typedef struct s_pos
{
	int		x;
	int		y;
}	t_pos;

typedef struct s_player
{
	t_pos	cur;
	t_pos	old;
	int		collected;
	int		steps;
	int		frame;
}	t_player;

typedef struct s_game
{
	int	exits;
	int	collectibles;
	int	players;
}	t_game;

typedef struct s_file
{
	t_list	*linked_file;
	char	**file_array;
	int		row_length;
	int		rows;
}	t_file;

typedef struct s_image
{
	char	*path;
	void	*img;
}	t_image;

typedef struct s_images
{
	t_image	player_frames[3];
	t_image	wall;
	t_image	path;
	t_image	collectibles;
	t_image	exit;
	t_image	step_counter;
}	t_images;

typedef struct s_file_data
{
	void		*mlx;
	void		*mlx_window;
	t_file		file;
	t_game		game;
	t_player	player;
	t_images	images;
}	t_game_data;

t_list	*get_file(int len, char **args);
int		validate_file(t_game_data *data);
void	start(t_game_data *data);
void	free_data(t_game_data *data);
int		store_file_as_2d_array(t_game_data *data);
void	move(int keycode, t_game_data *data);
void	draw_sprite(t_game_data *data, int y, int x, char c);
void	draw_clear(t_game_data *data);
void	draw_steps(t_game_data *data);
#endif
