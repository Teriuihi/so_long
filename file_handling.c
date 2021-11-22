#include "header_rename.h"
#include "libft/libft.h"

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
