int	ft_pow(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	nb *= ft_pow(nb, power - 1);
	return (nb);
}
