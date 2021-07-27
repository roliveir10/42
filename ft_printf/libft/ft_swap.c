void	ft_swap(void **a, void **b)
{
	void	*c;

	c = *a;
	*a = *b;
	*b = c;
}
