#include "libft.h"

/**
 * Clears all entries in the given t_list
 *
 * @param	lst	The pointer to the start of the t_list to add the entry to
 * @param	del
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = tmp;
	}
	*lst = NULL;
}
