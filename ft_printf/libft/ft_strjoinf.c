#include "libft.h"

char	*ft_strjoinf(char **str1, const char *str2)
{
	int		len;
	char	*fresh;

	len = ft_strlen(*str1) + ft_strlen(str2);
	fresh = (char *)ft_calloc(len + 1, sizeof(char));
	if (!fresh)
		return (NULL);
	ft_strcpy(fresh, *str1);
	ft_strcat(fresh, str2);
	ft_strdel(str1);
	return (fresh);
}
