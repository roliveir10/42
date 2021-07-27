#include "ft_printf.h"
#include "libft.h"

static char	*precision_with_negative(t_occurrence *occ, int offset)
{
	char	*tmp;
	char	*str;
	char	*value;

	if (offset < 1)
		return (occ->value);
	tmp = ft_strdup("-");
	str = (char *)ft_calloc(offset + 1, sizeof(char));
	ft_memset((void *)str, '0', offset);
	value = ft_strjoinf(&tmp, str);
	value = ft_strjoinf(&value, occ->value + 1);
	ft_strdel(&str);
	ft_strdel(&occ->value);
	return (value);
}

static char	*precision_with_str(t_occurrence *occ)
{
	char	*str;

	str = (char *)ft_calloc(occ->precision + 1, sizeof(char));
	ft_strlcpy(str, occ->value, occ->precision + 1);
	ft_strdel(&occ->value);
	return (str);
}

static char	*precision(t_occurrence *occ, int offset)
{
	char	*str;

	if (offset < 1)
		return (occ->value);
	str = (char *)ft_calloc(offset + 1, sizeof(char));
	ft_memset((void *)str, '0', offset);
	str = ft_strjoinf(&str, occ->value);
	ft_strdel(&occ->value);
	return (str);
}

char	*pflagdot(t_occurrence *occ)
{
	int		offset;

	offset = occ->precision - ft_strlen(occ->value);
	if (occ->flag & (TYPED + TYPEI + TYPEU + TYPEX + TYPE0X))
	{
		if (*occ->value == '-')
			return (precision_with_negative(occ, offset + 1));
		return (precision(occ, offset));
	}
	else if (occ->flag & TYPES)
		return (precision_with_str(occ));
	return (occ->value);
}
