#include "libft.h"

char	*pper(char *s)
{
	return (ft_strdup(s));
}

char	*ptypec(void *s, char *zero)
{
	unsigned char	c;
	char			*str;

	c = (unsigned char)s;
	*zero = c;
	str = (char *)ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = 0;
	return (str);
}

char	*ptypes(void *s, char *zero)
{
	char	*str;

	(void)zero;
	str = ft_strdup((char *)s);
	return (str);
}

char	*ptypep(void *s, char *zero)
{
	char			*str;
	char			*nbr;

	(void)zero;
	nbr = ft_uitoa_base((unsigned long)s, "0123456789abcdef");
	str = ft_strjoin("0x", nbr);
	ft_strdel(&nbr);
	return (str);
}

char	*ptyped(void *s, char *zero)
{
	char	*str;

	if ((int)s != 0)
		*zero = 1;
	str = ft_itoa((int)s);
	return (str);
}
