#include "header_rename.h"

size_t	ft_rowlen(const char *c)
{
	const char	*tmp;

	tmp = c;
	while (*tmp && *tmp != '\n')
		tmp++;
	return (tmp - c);
}


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

int	validate_file(t_file_data *data)
{
	t_list	*entry;

	entry = data->file;
	if (!validate_row(entry->content, "1", data))
		return (0);
	data->rows = 1;
	entry = entry->next;
	while (entry != NULL)
	{
		if (entry->next == NULL)
		{
			if (!validate_row(entry->content, "1", data))
				return (-1);
		}
		else
			if (!validate_row(entry->content, "01CEP", data))
				return (-1);
		entry = entry->next;
		data->rows++;
	}
	if (data->rows < 3)
		return (-2);
	return (1);
}