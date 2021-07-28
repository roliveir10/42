#include "libft.h"

void	ft_putstr_non_printable(char *str)
{
	int				i;
	const char		hex[17] = "0123456789abcdef";
	unsigned char	*ustr;

	i = 0;
	ustr = (unsigned char *)str;
	while (ustr[i])
	{
		if (!ft_isprint(ustr[i]))
		{
			ft_putchar('\\');
			ft_putchar(hex[ustr[i] / 16]);
			ft_putchar(hex[ustr[i] % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
