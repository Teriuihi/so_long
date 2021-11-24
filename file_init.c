#include "header_rename.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * Checks if a line is empty
 *
 * @param	row	Row to check
 *
 * @return	returns 0 if the line doesn't start empty
 * 			returns -1 if the line isn't fully empty
 * 			returns -2 if the line is fully empty
 */
int	empty_line(char *row)
{
	if (!ft_iswhite_space(*row))
		return (0);
	while (ft_iswhite_space(*row))
		row++;
	if (*row == '\0')
		return (-2);
	return (-1);
}

/**
 * Checks if a row contains invalid characters
 *
 * @param	row	Row to validate
 *
 * @return	Error code or 0 on success
 */
int	valid_row_content(char *row)
{
	int		err;
	char	*tmp;

	if (row == NULL)
		return (-1);
	err = empty_line(row);
	tmp = row;
	while (err == 0 && *tmp && *tmp != '\n')
	{
		if (!ft_contains("01CEP", *tmp))
			err = -1;
		tmp++;
	}
	if (err != 0)
		free(row);
	return (err);
}

/**
 * Loads a row, ignores empty lines
 *
 * @param	str		String to load as a row
 * @param	file	File to load from
 * @param	entry	Previous row entry
 * @param	fd		File descriptor to read from
 *
 * @return	Error code or 0 on success
 */
int	load_row(char **str, t_list **file, t_list **entry, int fd)
{
	int	valid;

	valid = valid_row_content(*str);
	if (valid == -1)
	{
		ft_lstclear(file, ft_lstdelentry);
		return (-1);
	}
	else if (valid == -2)
	{
		*str = get_next_line(fd);
		return (0);
	}
	*entry = ft_lstnew(*str);
	if (*entry == NULL)
	{
		ft_lstclear(file, ft_lstdelentry);
		return (-2);
	}
	else
		ft_lstadd_back(file, *entry);
	*str = get_next_line(fd);
	return (0);
}

/**
 * Loads a file (as long as no incorrect characters are found) trims empty lines
 *
 * @param	fd	File to read from
 *
 * @return	The first entry of a list of lines contained in the file
 */
t_list	*load_file(int fd)
{
	char	*str;
	t_list	*file;
	t_list	*entry;
	int		err;

	file = NULL;
	str = get_next_line(fd);
	while (str)
	{
		err = load_row(&str, &file, &entry, fd);
		if (err == 0)
			continue ;
		else if (err == -1)
			ft_printf("Error\nInvalid line in file.\n");
		else if (err == -2)
			ft_printf("Error\nUnable to allocate memory for row.\n");
	}
	if (!file)
		return (NULL);
	else
		return (file);
}

/**
 * Load the file and handle errors with arguments
 *
 * @param	len		Amount of arguments given
 * @param	args	Arguments given to program
 *
 * @return	File without whitespace or invalid characters
 */
t_list	*get_file(int len, char **args)
{
	int		fd;
	t_list	*file;

	if (len != 2)
	{
		ft_printf("Error\nInvalid amount of arguments expected 1 got %d.\n",
			len - 1);
		exit(0);
	}
	fd = open(args[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nUnable to read %s.\n", args[1]);
		exit(0);
	}
	file = load_file(fd);
	if (file == NULL)
	{
		write(1, "Error\nUnexpected error when reading file.\n", 6);
		exit(0);
	}
	return (file);
}
