#include "libft.h"

void	ft_print_digit_tables(int **mat, int x, int y)
{
	int		i;

	i = -1;
	while (++i < y)
		ft_print_digit(mat[i], x);
}
