#include "ft_printf.h"
#include "libft.h"

char	*pflagh(t_occurrence *occ)
{
	char	*tmp;

	if (!(occ->flag & (TYPEX + TYPE0X)))
		return (occ->value);
	if (occ->zero == 0)
		return (occ->value);
	if (occ->flag & TYPEX)
		tmp = ft_strjoin("0x", occ->value);
	else
		tmp = ft_strjoin("0X", occ->value);
	ft_strdel(&occ->value);
	return (tmp);
}

char	*pflagp(t_occurrence *occ)
{
	char	*str;

	if (*occ->value == '-')
		return (occ->value);
	if (occ->flag & (TYPED + TYPEI))
	{
		str = ft_strjoin("+", occ->value);
		ft_strdel(&occ->value);
		return (str);
	}
	return (occ->value);
}

char	*pflags(t_occurrence *occ)
{
	char	*str;

	if (occ->flag & (TYPED + TYPEI) && ft_atoi(occ->value) >= 0)
	{
		str = ft_strjoin(" ", occ->value);
		ft_strdel(&occ->value);
		return (str);
	}
	return (occ->value);
}

int	pflag0(t_occurrence *occ, int offset)
{
	char	*padding;
	char	*tmp;
	char	*value;

	padding = (char *)ft_calloc(offset + 1, sizeof(char));
	ft_memset((void *)padding, '0', offset);
	if (occ->flag & FLAGH)
	{
		tmp = ft_strndup(occ->value, 3);
		value = ft_strjoinf(&tmp, padding);
		value = ft_strjoinf(&value, occ->value + 2);
	}
	else if (occ->flag & (TYPED + TYPEI) && ft_atoi(occ->value) < 0)
	{
		tmp = ft_strndup(occ->value, 2);
		value = ft_strjoinf(&tmp, padding);
		value = ft_strjoinf(&value, occ->value + 1);
	}
	else
		value = ft_strjoin(padding, occ->value);
	ft_strdel(&padding);
	ft_strdel(&occ->value);
	occ->value = value;
	return (ft_strlen(occ->value));
}

int	pfield_width(t_occurrence *occ)
{
	char	offset;
	char	*padding;
	char	*tmp;

	offset = occ->field - ft_strlen(occ->value);
	if (occ->flag & TYPEC && occ->zero == 0)
		offset--;
	if (offset <= 0)
		return (occ->field - offset);
	if (occ->flag & FLAG0)
		return (pflag0(occ, offset));
	padding = (char *)ft_calloc(offset + 1, sizeof(char));
	ft_memset((void *)padding, ' ', offset);
	if (occ->flag & FLAGM)
		tmp = ft_filejoin(occ->value, padding, occ->field - offset, offset);
	else
		tmp = ft_filejoin(padding, occ->value, offset, occ->field - offset);
	ft_strdel(&padding);
	ft_strdel(&occ->value);
	occ->value = tmp;
	return (occ->field);
}
