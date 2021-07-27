unsigned int	ft_abs(int value)
{
	unsigned int	result;

	result = (unsigned int)value;
	if (value < 0)
		result = -value;
	return (result);
}
