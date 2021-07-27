#include "libft.h"

int	ft_check_base(const char *base)
{
	int		baselen;
	int		i;
	int		j;

	baselen = ft_strlen(base);
	if (baselen < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		i++;
	}
	return (baselen);
}
