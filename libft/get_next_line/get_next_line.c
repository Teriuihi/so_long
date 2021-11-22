#include <sys/uio.h>
#include <unistd.h>
#include <limits.h>
#include "get_next_line.h"
#include "../libft.h"

int	has_next_line(char *nl)
{
	if (nl == 0)
		return (0);
	while (*nl && *nl != '\n')
		nl++;
	if (*nl == '\n')
		return (1);
	return (0);
}

char	*get_next_line_2(int fd, char *buffer, char *nl, long len)
{
	if ((!len && !nl) || len < 0)
		return (NULL);
	else if (!len)
		return (ft_nl_substr(nl, buffer));
	nl = ft_strjoin(nl, buffer, 1);
	if (!nl)
		return (NULL);
	while (len == BUFFER_SIZE && !has_next_line(nl))
	{
		ft_memset(buffer, 0, ft_strlen_stop(buffer, 0));
		len = read(fd, buffer, BUFFER_SIZE);
		nl = ft_strjoin(nl, buffer, 1);
		if (!nl)
			return (NULL);
	}
	return (ft_nl_substr(nl, buffer));
}

/**
 * Get a new line from a file
 * @param fd file to look in
 * @return pointer to the start of the new line
 * 	(the char gets allocated)
 */
char	*get_next_line(int fd)
{
	char			*nl;
	long			len;
	static char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	nl = NULL;
	if (*buffer)
	{
		nl = ft_strjoin(nl, buffer, 1);
		if (!nl)
			return (NULL);
	}
	if (has_next_line(nl))
		return (ft_nl_substr(nl, buffer));
	len = read(fd, buffer, BUFFER_SIZE);
	return (get_next_line_2(fd, buffer, nl, len));
}
