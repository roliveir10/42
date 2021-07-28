#include "libft.h"

static void	ft_print_base(unsigned int nbr, unsigned int baselen,
		const char *base)
{
	if (nbr > baselen - 1)
		ft_print_base(nbr / baselen, baselen, base);
	ft_putchar(base[nbr % baselen]);
}

void	ft_putnbr_base(int nbr, const char *base)
{
	unsigned int	baselen;
	unsigned int	unbr;

	unbr = (unsigned int)nbr;
	baselen = ft_check_base(base);
	if (baselen == 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		unbr = -nbr;
	}
	ft_print_base(unbr, baselen, base);
}
