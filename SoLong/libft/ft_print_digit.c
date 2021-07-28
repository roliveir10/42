#include "libft.h"

void	ft_print_digit(int *tab, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		ft_putnbr(tab[i]);
		if (i + 1 != size)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
