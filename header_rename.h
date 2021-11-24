#ifndef HEADER_RENAME_H
# define HEADER_RENAME_H
# include <stdlib.h>
# include "libft/libft.h"
typedef struct s_file_data
{
	t_list	*file;
	int		exits;
	int		collectibles;
	int		player;
	size_t	row_length;
	size_t	rows;
}	t_file_data;

t_list	*get_file(int len, char **args);
int		validate_file(t_file_data *data);
void	start(t_file_data *data);
void	free_data(t_file_data *data);
#endif
