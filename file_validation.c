/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_validation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 17:57:22 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 17:57:22 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

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
		data->game.exits++;
	else if (c == 'C')
		data->game.collectibles++;
	else if (c == 'P')
	{
		if (data->game.players == 1)
			*arr = '0';
		else
			data->game.players++;
	}
}

int	validate_row_pt2(char *row, char *allowed_chars, t_game_data *data)
{
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
	if (entry->content == NULL)
		return (0);
	free(row);
	row = entry->content;
	if (data->file.row_length == 0)
		data->file.row_length = ft_strlen(row);
	if ((int) ft_strlen(row) != data->file.row_length)
		return (0);
	return (validate_row_pt2(row, allowed_chars, data));
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

	entry = data->file.linked_file;
	if (!validate_row(entry, "1", data))
		return (-1);
	data->file.rows = 1;
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
		data->file.rows++;
	}
	if (data->file.rows < 3)
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
		ft_printf("Error\nInvalid row at row %d.\n", err, data->file.rows);
	else if (err == -4)
		ft_printf("Error\nExpected 3 or more rows, found %d.\n", data->file.rows);
	if (err < 0)
		return (err);
	if (data->game.players != 1)
	{
		ft_printf("Error\nExpected 1 player found, %d.\n", data->game.players);
		err = -5;
	}
	if (data->game.collectibles < 1)
	{
		ft_printf("Error\nExpected 1 or more collectibles, found none.\n");
		err = -6;
	}
	if (data->game.exits < 1)
	{
		ft_printf("Error\nExpected 1 or more exits, found none.\n");
		err = -7;
	}
	return (err);
}
