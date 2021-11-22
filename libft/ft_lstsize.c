#include "libft.h"

/**
 * Calculates the size of the given t_list
 *
 * @param	lst	The start of the t_list to get the size of
 *
 * @return	The size of the given t_list as an integer
 */
int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while ((lst->next))
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
