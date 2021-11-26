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
}	t_player;

typedef struct s_file_data
{
	t_list		*file;
	char		**file_array;
	int			exits;
	int			collectibles;
	int			players;
	int			row_length;
	int			rows;
	void		*mlx;
	void		*mlx_window;
	t_player	player;
}	t_game_data;

t_list	*get_file(int len, char **args);
int		validate_file(t_game_data *data);
void	start(t_game_data *data);
void	free_data(t_game_data *data);
int		store_file_as_2d_array(t_game_data *data);
#endif
