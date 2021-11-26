#include "headers/header_rename.h"

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

	data->file_array = ft_calloc(data->rows, sizeof(char *));
	if (data->file_array == NULL)
		return (0);
	i = 0;
	entry = data->file;
	while (entry != NULL)
	{
		data->file_array[i] = entry->content;
		entry = entry->next;
		i++;
	}
	return (1);
}

/**
 * Update the counters for the game
 * 	if a player is found when there is a player already they are changed
 * 	to background
 * @param	arr		Array to check the first character for
 * @param	data	Game data
 */
void	update_data(char *arr, t_game_data *data)
{
	char	c;

	c = *arr;
	if (c == 'E')
		data->exits++;
	else if (c == 'C')
		data->collectibles++;
	else if (c == 'P')
	{
		if (data->players == 1)
			*arr = '0';
		else
			data->players++;
	}
}

/**
 * Validate a row
 *
 * @param	row				row to validate
 * @param	allowed_chars	Allowed characters
 * @param	data			Data to validate
 *
 * @return
 */
int	validate_row(t_list *entry, char *allowed_chars, t_game_data *data)
{
	char	*row;

	row = entry->content;
	if (row == NULL)
		return (0);
	entry->content = ft_strtrim(row, "\n");
	free(row);
	row = entry->content;
	if (data->row_length == 0)
		data->row_length = ft_strlen(row);
	if ((int) ft_strlen(row) != data->row_length)
		return (0);
	if (*row != '1')
		return (0);
	row++;
	while (*row && *row != '\n')
	{
		if (!ft_contains(allowed_chars, *row))
			return (0);
		update_data(row, data);
		row++;
	}
	if (*(row - 1) != '1')
		return (0);
	return (1);
}

/**
 * Validate a file
 *
 * @param	data	Data for file to validate
 *
 * @return	Error code or 0 on success
 */
int	validate_file_internal(t_game_data *data)
{
	t_list	*entry;

	entry = data->file;
	if (!validate_row(entry, "1", data))
		return (-1);
	data->rows = 1;
	entry = entry->next;
	while (entry != NULL)
	{
		if (entry->next == NULL)
		{
			if (!validate_row(entry, "1", data))
				return (-2);
		}
		else
			if (!validate_row(entry, "01CEP", data))
				return (-3);
		entry = entry->next;
		data->rows++;
	}
	if (data->rows < 3)
		return (-4);
	return (0);
}

/**
 * Handles validation errors
 *
 * @param	data	Data for file to validate
 *
 * @return	0 for valid files
 */
int	validate_file(t_game_data *data)
{
	int	err;

	err = validate_file_internal(data);
	if (err == -1 || err == -2 || err == -3)
		ft_printf("Error\n%d: invalid row at row %d.\n", err, data->rows);
	else if (err == -4)
		ft_printf("Error\nExpected 3 or more rows, found %d.\n", data->rows);
	if (err < 0)
		return (err);
	if (data->players != 1)
	{
		ft_printf("Error\nExpected 1 player found, %d.\n", data->players);
		err = -5;
	}
	if (data->collectibles < 1)
	{
		ft_printf("Error\nExpected 1 or more collectibles, found none.\n");
		err = -6;
	}
	if (data->exits < 1)
	{
		ft_printf("Error\nExpected 1 or more exits, found none.\n");
		err = -7;
	}
	return (err);
}
