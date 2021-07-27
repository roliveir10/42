#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

void	flush_stack(char **stack, size_t n)
{
	write(1, *stack, n);
	ft_bzero(*stack, n);
}

int	put_char_in_stack(char **stack, const char *str, size_t n,
	int *char_r)
{
	size_t		i;
	size_t		charput;
	static int	i_instack = 0;

	if (!*char_r)
		i_instack = 0;
	i = i_instack;
	charput = 0;
	*char_r += n;
	while (charput < n)
	{
		if (i == STACK_SIZE)
		{
			flush_stack(stack, STACK_SIZE);
			i = 0;
		}
		(*stack)[i] = str[charput];
		charput++;
		i++;
	}
	i_instack = i;
	return (i_instack);
}

char	**get_stack(void)
{
	static char	*stack = NULL;

	if (!stack)
		stack = (char *)ft_calloc(STACK_SIZE + 1, sizeof(char));
	return (&stack);
}

static t_occurrence	parse_occurrence(const char *str, int *i, va_list ap)
{
	t_occurrence	occ;
	unsigned int	bit;

	ft_bzero(&occ, sizeof(t_occurrence));
	while (str[*i] && !ft_strchr(CONVERSION, str[*i]))
	{
		bit = get_flag_bit(str[*i]);
		occ.flag |= bit;
		if (bit & FLAGDOT)
		{
			(*i)++;
			occ.precision = ft_atoip(str, i);
		}
		else if (ft_isdigit(str[*i]) && !(bit & FLAG0))
			occ.field = ft_atoip(str, i);
		else
			(*i)++;
	}
	if (str[*i])
	{
		occ.flag |= get_flag_bit(str[*i]);
		occ.value = get_arg_in_str(ap, occ.flag, &occ.zero);
	}
	return (occ);
}

int	put_occurrence_in_stack(const char *str, int i, va_list ap,
		int *char_r)
{
	t_occurrence	occ;
	int				occlen;

	occ = parse_occurrence(str, &i, ap);
	if (!str[i])
		return (i);
	occlen = create_occurrence(&occ);
	put_char_in_stack(get_stack(), occ.value, occlen, char_r);
	ft_strdel(&occ.value);
	return (i + 1);
}
