#include "libft.h"

char	*ft_strtrim(char const *s1, char const *s2)
{
	int		start;
	int		end;

	start = 0;
	while (ft_strchr(s2, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > 0 && ft_strchr(s2, s1[end - 1]))
		end--;
	if (end <= start)
		return ((char *)ft_calloc(1, sizeof(char)));
	return (ft_substr(s1, start, end - start));
}
