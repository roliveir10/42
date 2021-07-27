#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

static int	read_arg(va_list ap, const char *arg, int *cread)
{
	int	i;
	int	state;

	i = 0;
	state = 0;
	while (arg[i])
	{
		if (arg[i] == '%')
		{
			put_char_in_stack(get_stack(), &arg[state], i - state, cread);
			i = put_occurrence_in_stack(arg, i + 1, ap, cread);
			state = i;
		}
		else
			i++;
	}
	return (put_char_in_stack(get_stack(), &arg[state], i - state, cread));
}

int	ft_printf(const char *arg, ...)
{
	va_list	ap;
	int		char_r;
	int		i_instack;

	char_r = 0;
	va_start(ap, arg);
	i_instack = read_arg(ap, arg, &char_r);
	flush_stack(get_stack(), i_instack);
	ft_strdel(get_stack());
	va_end(ap);
	return (char_r);
}
