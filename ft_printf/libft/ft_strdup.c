#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		ls1;
	char	*new;

	ls1 = ft_strlen(s1) + 1;
	new = ft_calloc(ls1, sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, ls1);
	return (new);
}
