#include <unistd.h>
#include "headers/so_long.h"

void	init_images(t_game_data *data)
{
	data->images.path.path = "./images/path.png";
	data->images.wall.path = "./images/wall.png";
	data->images.exit.path = "./images/exit.png";
	data->images.collectibles.path = "./images/collectibles.png";
	data->images.step_counter.path = "./images/step_counter.png";
	data->images.player_frames[0].path = "./images/player0.png";
	data->images.player_frames[1].path = "./images/player1.png";
	data->images.player_frames[2].path = "./images/player2.png";
}

int	main(int len, char **args)
{
	t_game_data	*data;

	data = ft_calloc(1, sizeof(t_game_data));
	if (data == NULL)
	{
		ft_printf("Error\nUnable to allocate memory for file data.\n");
		exit(0);
	}
	data->file.linked_file = get_file(len, args);
	if (validate_file(data) || !store_file_as_2d_array(data))
	{
		free_data(data);
		exit(0);
	}
	init_images(data);
	start(data);
	return (0);
}
//TODO fix prefix and suffix checks in libft