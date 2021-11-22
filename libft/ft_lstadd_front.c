#include "libft.h"

/**
 * Adds a new entry to the front of the t_list
 *
 * @param	lst	The pointer to the start of the t_list to add the entry to
 * @param	new	The new entry to add to the t_list
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
