#include "libft.h"

static int	ft_skip_occurrence(const char *s, char c, char word, int i)
{
	if (word)
	{
		while (s[i] && s[i] != c)
			i++;
	}
	else
	{
		while (s[i] == c)
			i++;
	}
	return (i);
}

static int	ft_count_word(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		i = ft_skip_occurrence(s, c, 0, i);
		if (s[i])
			count++;
		i = ft_skip_occurrence(s, c, 1, i);
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**tab;
	int		count_w;
	int		st;
	int		end;

	words = ft_count_word(s, c);
	tab = ft_calloc(words + 1, sizeof(char *));
	count_w = 0;
	st = 0;
	while (tab && count_w < words)
	{
		st = ft_skip_occurrence(s, c, 0, st);
		end = ft_skip_occurrence(s, c, 1, st);
		tab[count_w] = ft_substr(s, st, end - st);
		if (!tab[count_w])
			return (NULL);
		st += end - st;
		count_w++;
	}
	return (tab);
}
