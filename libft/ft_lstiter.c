#include "libft.h"

/**
 * Iterates through a given t_list and execute a given function
 * 	on each entries content
 *
 * @param	lst	The t_list to iterate through
 * @param	f	The function to apply on each t_list entries content
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst->next)
	{
		f(lst->content);
		lst = lst->next;
	}
	f(lst->content);
}
