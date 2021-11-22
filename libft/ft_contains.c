#include "libft.h"

/**
 * Check if a string contains a char
 * @param str String to check
 * @param c Char to check for
 * @return The location of c in str
 */
char	*ft_contains(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		else
			str++;
	}
	return (NULL);
}
