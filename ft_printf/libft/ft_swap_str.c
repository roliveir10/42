void	ft_swap_str(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}
