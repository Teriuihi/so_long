#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <wchar.h>
char		*get_next_line(int fd);
char		*ft_nl_substr(void *nl, char *buffer);
char		*ft_strjoin(char *nl, char *str, int clear);
size_t		ft_strlen_stop(const char *c, char stop);
const int	BUFFER_SIZE = 100;
#endif
