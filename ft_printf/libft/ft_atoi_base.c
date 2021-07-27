#include "libft.h"

static int	ft_is_in_base(char c, const char *base, int *index)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			*index = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int			i;
	int			sign;
	int			index;
	int			nbr;
	int			len_base;

	sign = 1;
	nbr = 0;
	i = 0;
	len_base = ft_check_base(base);
	if (len_base == 0)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_is_in_base(str[i], base, &index))
	{
		nbr = nbr * len_base + index;
		i++;
	}
	return (nbr * sign);
}
