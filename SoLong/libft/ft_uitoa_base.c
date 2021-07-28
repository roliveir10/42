#include "libft.h"

static void	ft_putnbr_in_buffer(unsigned long long nbr, char *base,
		int len, char *buffer)
{
	if (nbr > (unsigned long long)len - 1)
		ft_putnbr_in_buffer(nbr / len, base, len, buffer);
	ft_strncat(buffer, &base[nbr % len], 1);
}

char	*ft_uitoa_base(unsigned long long nbr, char *base_to)
{
	char	buffer[128];

	buffer[0] = 0;
	ft_putnbr_in_buffer(nbr, base_to, ft_strlen(base_to), buffer);
	return (ft_strdup(buffer));
}
