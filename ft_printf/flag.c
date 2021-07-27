#include <stdarg.h>
#include "ft_printf.h"

unsigned int	get_flag_bit(char c)
{
	const char			flag[NBR_FLAG] = "%cspdiuxX-0.# +";
	const unsigned int	bit[NBR_FLAG] = {PER, TYPEC, TYPES, TYPEP, TYPED,
			TYPEI, TYPEU, TYPEX, TYPE0X, FLAGM, FLAG0, FLAGDOT,
			FLAGH, FLAGS, FLAGP};
	int					i;

	i = 0;
	while (flag[i])
	{
		if (flag[i] == c)
			return (bit[i]);
		i++;
	}
	return (0);
}

char	*get_arg_in_str(va_list ap, unsigned int flag, char *zero)
{
	const unsigned int	bit[NBR_CONVERSION] = {TYPEC, TYPES, TYPEP, TYPED,
				TYPEI, TYPEU, TYPEX, TYPE0X};
	static	char		*(*f[NBR_CONVERSION])(void *, char *) = {
		ptypec, ptypes, ptypep, ptyped, ptyped, ptypeu, ptypex, ptypeX};
	int					i;

	if (flag & PER)
		return (pper("%"));
	i = 0;
	while (i < NBR_CONVERSION)
	{
		if (flag & bit[i])
			return (f[i](va_arg(ap, void *), zero));
		i++;
	}
	return (NULL);
}

static unsigned int	apply_flag_rules(unsigned int flag)
{
	if (flag & FLAG0 && flag & FLAGDOT && flag & (TYPED + TYPEI + TYPEU
			+ TYPEX + TYPE0X))
		flag &= ~FLAG0;
	if (flag & FLAG0 && flag & FLAGM)
		flag &= ~FLAG0;
	if (flag & FLAGP && flag & FLAGS)
		flag &= ~FLAGS;
	return (flag);
}

int	create_occurrence(t_occurrence *occ)
{
	const unsigned int	flag[4] = {FLAGDOT, FLAGP, FLAGH, FLAGS};
	static	char		*(*f[4])(t_occurrence *) = {pflagdot, pflagp,
		pflagh, pflags};
	int					i;

	i = 0;
	occ->flag = apply_flag_rules(occ->flag);
	while (i < 4)
	{
		if (occ->flag & flag[i])
			occ->value = f[i](occ);
		i++;
	}
	return (pfield_width(occ));
}
