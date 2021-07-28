int	ft_clamp(int value, int lo, int hi)
{
	if (value < lo)
		return (lo);
	else if (value > hi)
		return (hi);
	else
		return (value);
}
