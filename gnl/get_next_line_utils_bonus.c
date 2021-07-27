#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	destlen;

	i = 0;
	destlen = ft_strlen(dest);
	while (src[i])
	{
		dest[destlen] = src[i];
		destlen++;
		i++;
	}
	dest[destlen] = 0;
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (i < n - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	len_new;
	char	*new;

	len_s = ft_strlen(s);
	if (start >= len_s)
		return ((char *)malloc(sizeof(char)));
	if (start + len >= len_s)
		len_new = len_s - start;
	else
		len_new = len;
	new = (char *)malloc(sizeof(char) * (len_new + 1));
	if (new)
		ft_strlcpy(new, &s[start], len_new + 1);
	return (new);
}

char	*ft_strjoinf(char **str1, const char *str2)
{
	int		len;
	char	*fresh;

	len = ft_strlen(*str1) + ft_strlen(str2);
	fresh = (char *)malloc(sizeof(char) * (len + 1));
	if (!fresh)
		return (NULL);
	ft_strlcpy(fresh, *str1, ft_strlen(*str1) + 1);
	ft_strcat(fresh, str2);
	free(*str1);
	*str1 = NULL;
	return (fresh);
}
