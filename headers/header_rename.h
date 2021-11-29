#ifndef HEADER_RENAME_H
# define HEADER_RENAME_H
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_player
{
	int	x;
	int	y;
	int	new_x;
	int	new_y;
	int	collected;
	int	steps;
	int	frame;
}	t_player;

typedef struct s_game
{
	int	exits;
	int	collectibles;
	int	players;
	int	running;
}	t_game;

typedef struct s_file
{
	t_list	*linked_file;
	char	**file_array;
	int		row_length;
	int		rows;
}	t_file;

typedef struct s_file_data
{
	void		*mlx;
	void		*mlx_window;
	t_file		file;
	t_game		game;
	t_player	player;
}	t_game_data;

t_list	*get_file(int len, char **args);
int		validate_file(t_game_data *data);
void	start(t_game_data *data);
void	free_data(t_game_data *data);
int		store_file_as_2d_array(t_game_data *data);
void	move(int keycode, t_game_data *data);
void	*animation_start(void *ptr);
#endif
