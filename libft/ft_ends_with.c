#include "libft.h"

/**
 * Checks if a string ends with a specific suffix
 *
 * @param	str		String to check the suffix for
 * @param	suffix	Suffix to check for
 *
 * @return	1 if the string ends with the suffix, 0 if not
 */
int	ft_ends_with(char *str, char *suffix)
{
	int	len;

	len = ft_strlen(suffix);
	return (ft_strncmp(str + ft_strlen(str) - len, suffix, len) == 0);
}
