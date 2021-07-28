int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (c >= 'a' && c <= 'z');
}
