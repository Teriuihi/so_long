#include "headers/header_rename.h"

/**
 * Calculates the length of a row (row's can stop at \0 or \n)
 *
 * @param	row	Row to calculate length for
 *
 * @return	Length of row
 */
size_t	ft_rowlen(const char *row)
{
	const char	*tmp;

	tmp = row;
	while (*tmp && *tmp != '\n')
		tmp++;
	return (tmp - row);
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
int	validate_row(char *row, char *allowed_chars, t_file_data *data)
{
	if (row == NULL)
		return (0);
	if (data->row_length == 0)
		data->row_length = ft_rowlen(row);
	if (ft_rowlen(row) != data->row_length)
		return (0);
	if (*row != '1')
		return (0);
	row++;
	while (*row && *row != '\n')
	{
		if (!ft_contains(allowed_chars, *row))
			return (0);
		if (*row == 'E')
			data->exits++;
		else if (*row == 'C')
			data->collectibles++;
		else if (*row == 'P')
			data->player++;
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
	if (!validate_row(entry->content, "1", data))
		return (-1);
	data->rows = 1;
	entry = entry->next;
	while (entry != NULL)
	{
		if (entry->next == NULL)
		{
			if (!validate_row(entry->content, "1", data))
				return (-2);
		}
		else
			if (!validate_row(entry->content, "01CEP", data))
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
		ft_printf("Error\nInvalid row at row %d.\n", data->rows);
	else if (err == -4)
		ft_printf("Error\nExpected 3 or more rows, found %d.\n",
			data->rows);
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
	if (data->exits != 1)
	{
		ft_printf("Error\nExpected 1 or more exits, found none.\n");
		err = -7;
	}
	return (err);
}
