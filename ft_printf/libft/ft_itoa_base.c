#include "libft.h"

static void	ft_putnbr_in_buffer(long long nbr, char *base,
		int len, char *buffer)
{
	unsigned long long	unbr;

	unbr = (unsigned long long)nbr;
	if (nbr < 0)
	{
		ft_strncat(buffer, "-", 1);
		unbr = -nbr;
	}
	if (unbr > (unsigned long long)len - 1)
		ft_putnbr_in_buffer(unbr / len, base, len, buffer);
	ft_strncat(buffer, &base[unbr % len], 1);
}

char	*ft_itoa_base(long long nbr, char *base_to)
{
	char	buffer[128];

	buffer[0] = 0;
	ft_putnbr_in_buffer(nbr, base_to, ft_strlen(base_to), buffer);
	return (ft_strdup(buffer));
}
