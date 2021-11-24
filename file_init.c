#include "header_rename.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

void	*free_list(t_list **file)
{
	ft_lstclear(file, ft_lstdelentry);
	return (NULL);
}

int	valid_line(char *str)
{
	while (*str && *str != '\n')
	{
		if (!ft_contains("01CEP", *str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * Loads a file (as long as no incorrect characters are found) trims empty lines
 * @param fd file to read from
 * @return the first entry of a list of lines contained in the file
 */
t_list	*load_file(int fd)
{
	char	*str;
	t_list	**file;
	t_list	*entry;

	file = NULL;
	str = get_next_line(fd);
	while (str)
	{
		if (ft_iswhite_space(*str))
			continue ;
		if (!valid_line(str))
			return (free_list(file));
		entry = ft_lstnew(str);
		if (entry == NULL)
			return (free_list(file));
		if (file == NULL)
			file = &entry;
		else
			ft_lstadd_back(file, entry);
		str = get_next_line(fd);
	}
	if (!file)
		return (NULL);
	else
		return (*file);
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
