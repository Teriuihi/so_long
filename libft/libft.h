#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
char	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*get_next_line(int fd);
int		ft_iswhite_space(char c);
char	*ft_contains(char *str, char c);
void	*ft_calloc(size_t count, size_t size);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(long n, int fd);
size_t	ft_strlen(const char *c);
char	*ft_itoa(int n);
int		ft_printf(const char *str, ...);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelentry(void *content);
#endif
