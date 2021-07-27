#include "libft.h"
#include <stdlib.h>

void	ft_del_words_tables(char ***tab)
{
	char	**tmp;

	if (!tab || !*tab)
		return ;
	tmp = *tab;
	while (**tab)
	{
		ft_strdel(*tab);
		*tab += 1;
	}
	free(tmp);
	tmp = NULL;
}
