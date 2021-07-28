void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	c;

	i = 0;
	while (i + 1 < size)
	{
		if (tab[i] > tab[i + 1])
		{
			c = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = c;
			i = -1;
		}
		i++;
	}
}
