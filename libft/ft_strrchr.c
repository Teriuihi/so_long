#include <stdlib.h>

/**
 * Finds the first occurrence of c in s
 *
 * @param	s	String to look through
 * @param	c	Char to look for
 *
 * @return	The first location of c in *s, or NULL if there is none
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*mem;
	char	chr;

	mem = NULL;
	chr = (char) c;
	while (*s)
	{
		if (*s == chr)
			mem = (char *)s;
		s++;
	}
	if (*s == chr)
		mem = ((char *)s);
	return (mem);
}
