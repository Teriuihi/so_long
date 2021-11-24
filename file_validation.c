#include "headers/header_rename.h"

void	update_data(char c, t_file_data *data)
{
	if (c == 'E')
		data->exits++;
	else if (c == 'C')
		data->collectibles++;
	else if (c == 'P')
		data->player++;
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
int	validate_row(t_list *entry, char *allowed_chars, t_file_data *data)
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
	if (ft_strlen(row) != data->row_length)
		return (0);
	if (*row != '1')
		return (0);
	row++;
	while (*row && *row != '\n')
	{
		if (!ft_contains(allowed_chars, *row))
			return (0);
		update_data(*row, data);
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
int	validate_file_internal(t_file_data *data)
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
int	validate_file(t_file_data *data)
{
	int	err;

	err = validate_file_internal(data);
	if (err == -1 || err == -2 || err == -3)
		ft_printf("Error\n%d: invalid row at row %d.\n", err, data->rows);
	else if (err == -4)
		ft_printf("Error\nExpected 3 or more rows, found %d.\n", data->rows);
	if (err < 0)
		return (err);
	if (data->player != 1)
	{
		ft_printf("Error\nExpected 1 player found, %d.\n", data->player);
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
