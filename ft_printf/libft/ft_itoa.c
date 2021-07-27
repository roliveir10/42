#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(long long n)
{
	char				buffer[128];
	int					len;
	int					i;
	unsigned long long	u_n;

	len = ft_nbrlen(n);
	ft_bzero(buffer, 128);
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
