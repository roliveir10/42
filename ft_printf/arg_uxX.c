#include "libft.h"

char	*ptypeu(void *s, char *zero)
{
	char	*str;

	if ((unsigned int)s != 0)
		*zero = 1;
	str = ft_itoa((unsigned int)s);
	return (str);
}

char	*ptypex(void *s, char *zero)
{
	char	*str;

	if ((unsigned int)s != 0)
		*zero = 1;
	str = ft_uitoa_base((unsigned int)s, "0123456789abcdef");
	return (str);
}

char	*ptypeX(void *s, char *zero)
{
	char	*str;

	if ((unsigned int)s != 0)
		*zero = 1;
	str = ft_uitoa_base((unsigned int)s, "0123456789ABCDEF");
	return (str);
}
