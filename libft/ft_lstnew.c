#include "libft.h"

/**
 * Creates a new t_list entry containing the given content
 *
 * @param	content	The content to put in the new t_list entry
 *
 * @return	A new t_list entry with the given content
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*start;

	start = malloc(sizeof(*start));
	if (start == 0)
		return (NULL);
	start->content = content;
	start->next = NULL;
	return (start);
}
