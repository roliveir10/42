#include "libft.h"

int	ft_atoip(const char *str, int *i)
{
	int	is_neg;
	int	nbr;

	nbr = 0;
	is_neg = 1;
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '-')
		is_neg = -1;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nbr = nbr * 10 + str[*i] - 48;
		(*i)++;
	}
	return (is_neg * nbr);
}
