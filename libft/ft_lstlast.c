#include "libft.h"
/**
 * Go to the end of the t_list and return that entry
 *
 * @param	lst	The t_list to iterate through
 *
 * @return	The last entry of the given t_list
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
