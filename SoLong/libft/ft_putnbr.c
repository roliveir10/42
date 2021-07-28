#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	nbr;

	nbr = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar('-');
		nbr = -n;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}
