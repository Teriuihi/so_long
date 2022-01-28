/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 17:57:29 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 17:57:29 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "headers/so_long.h"

/**
 * Stores data from file in a 2d array for faster access
 *
 * @param	data	All game data
 *
 * @return	0 on failure, 1 on success
 */
int	store_file_as_2d_array(t_game_data *data)
{
	t_list	*entry;
	int		i;

	data->file.file_array = ft_calloc(data->file.rows, sizeof(char *));
	if (data->file.file_array == NULL)
		return (0);
	i = 0;
	entry = data->file.linked_file;
	while (entry != NULL)
	{
		data->file.file_array[i] = entry->content;
		entry = entry->next;
		i++;
	}
	return (1);
}

/**
 * Store the path for all images
 *
 * @param	data	all game data
 */
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

/**
 * Initialize data
 * 	Parse, validate, and store file
 * 	Store image paths
 * 	Start game
 *
 * @param	len		Amount of arguments
 * @param	args	All arguments given to program
 *
 * @return	0
 */
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
