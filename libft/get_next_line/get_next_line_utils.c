#include <stdlib.h>
#include <wchar.h>
#include "get_next_line.h"
#include "../libft.h"

size_t	ft_strlen_stop(const char *c, char stop)
{
	const char	*tmp;

	if (!c)
		return (0);
	tmp = c;
	while (*tmp && *tmp != stop)
		tmp++;
	return (tmp - c);
}

char	*ft_nl_substr(void *nl, char *buffer)
{
	char	*substr;
	size_t	len;

	len = ft_strlen_stop(nl, '\n');
	substr = malloc((len + 2) * sizeof(char));
	if (substr == 0)
		return (NULL);
	ft_memset(substr, 0, len + 2);
	ft_memcpy(substr, nl, len + 1);
	ft_memcpy(buffer, nl + len + 1, ft_strlen_stop(nl, 0) - len);
	free(nl);
	return (substr);
}

char	*ft_strjoin(char *nl, char *str, int clear)
{
	int		nl_len;
	int		str_len;
	char	*res;

	if (!nl && !str)
		return (NULL);
	else if (!str)
		return (nl);
	nl_len = ft_strlen_stop(nl, 0);
	str_len = ft_strlen_stop(str, 0);
	res = malloc((nl_len + str_len + 1) * sizeof(char));
	if (res == 0)
		return (0);
	ft_memset(res, 0, nl_len + str_len + 1);
	if (nl_len)
		ft_memcpy(res, (void *)nl, nl_len);
	ft_memcpy(res + nl_len, (void *)str, str_len);
	if (nl)
		free(nl);
	if (clear)
		ft_memset(str, 0, ft_strlen_stop(str, 0));
	return (res);
}
