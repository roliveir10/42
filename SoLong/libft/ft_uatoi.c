#include "libft.h"

unsigned int	ft_uatoi(const char *str)
{
	int				i;
	unsigned int	nb;
	int				sign;

	sign = 1;
	i = 0;
	nb = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (sign * nb);
}
