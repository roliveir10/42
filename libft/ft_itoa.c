#include <stdlib.h>
#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			buffer[16];
	int				len;
	int				i;
	unsigned int	u_n;

	len = ft_nbrlen(n);
	ft_bzero(buffer, 16);
	buffer[0] = '0';
	u_n = n;
	if (n < 0)
	{
		buffer[0] = '-';
		u_n = -n;
	}
	i = len - 1;
	while (u_n)
	{
		buffer[i] = u_n % 10 + 48;
		u_n = u_n / 10;
		i--;
	}
	return (ft_strdup(buffer));
}
