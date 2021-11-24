#include "header_rename.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

void	*free_list(t_list **file)
{
	ft_lstclear(file, ft_lstdelentry);
	return (NULL);
}

/**
 * Checks if a line is empty
 * @param str line to check
 * @return returns 1 if the line doesn't start empty
 * 	returns -1 if the line isn't fully empty
 * 	returns -2 if the line is fully empty
 */
int	empty_line(char *str)
{
	if (!ft_iswhite_space(*str))
		return (1);
	while (ft_iswhite_space(*str))
		str++;
	if (*str == '\0')
		return (-2);
	return (-1);
}

int	valid_line(char *str)
{
	int		err;
	char	*tmp;

	if (str == NULL)
		return (-1);
	err = empty_line(str);
	tmp = str;
	while (err == 1 && *tmp && *tmp != '\n')
	{
		if (!ft_contains("01CEP", *tmp))
			err = -1;
		tmp++;
	}
	if (err != 1)
		free(str);
	return (err);
}

/**
 * Loads a file (as long as no incorrect characters are found) trims empty lines
 * @param fd file to read from
 * @return the first entry of a list of lines contained in the file
 */
t_list	*load_file(int fd)
{
	char	*str;
	t_list	*file;
	t_list	*entry;
	int		valid;

	file = NULL;
	str = get_next_line(fd);
	while (str)
	{
		valid = valid_line(str);
		if (valid == -1)
			return (free_list(&file));
		else if (valid == -2)
		{
			str = get_next_line(fd);
			continue ;
		}
		entry = ft_lstnew(str);
		if (entry == NULL)
			return (free_list(&file));
		else
			ft_lstadd_back(&file, entry);
		str = get_next_line(fd);
	}
	if (!file)
		return (NULL);
	else
		return (file);
}

/**
 * Load the file and handle errors with arguments
 * @param len amount of arguments given
 * @param args arguments given to program
 * @return file without whitespace or invalid characters
 */
t_list	*get_file(int len, char **args)
{
	int		fd;
	t_list	*file;

	if (len != 2)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	fd = open(args[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	file = load_file(fd);
	if (file == NULL)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	return (file);
}
