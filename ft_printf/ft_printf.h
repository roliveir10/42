#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdarg.h>

# define STACK_SIZE 128
# define NBR_CONVERSION 8
# define NBR_FLAG 15
# define CONVERSION "cspdiuxX%"

typedef enum e_type
{
	PER = 0x01,
	TYPEC = 0x02,
	TYPES = 0x04,
	TYPEP = 0x08,
	TYPED = 0x10,
	TYPEI = 0x20,
	TYPEU = 0x40,
	TYPEX = 0x80,
	TYPE0X = 0x100,
	FLAGM = 0x200,
	FLAG0 = 0x400,
	FLAGDOT = 0x800,
	FLAGH = 0x1000,
	FLAGS = 0x2000,
	FLAGP = 0x4000
}				t_type;

typedef struct s_occurrence
{
	unsigned int	flag;
	int				field;
	int				precision;
	char			*value;
	char			zero;
}				t_occurrence;

int				ft_printf(const char *arg, ...);
int				put_occurrence_in_stack(const char *str, int i,
					va_list ap, int *char_r);
char			**get_stack(void);
int				put_char_in_stack(char **stack, const char *str,
					size_t n, int *char_r);
void			flush_stack(char **stack, size_t n);
unsigned int	get_flag_bit(char c);
char			*get_arg_in_str(va_list ap, unsigned int flag, char *zero);
int				create_occurrence(t_occurrence *occ);
char			*pper(char *s);
char			*ptypec(void *s, char *zero);
char			*ptypes(void *s, char *zero);
char			*ptypep(void *s, char *zero);
char			*ptyped(void *s, char *zero);
char			*ptypeu(void *s, char *zero);
char			*ptypex(void *s, char *zero);
char			*ptypeX(void *s, char *zero);
char			*pflagdot(t_occurrence *occ);
char			*pflagp(t_occurrence *occ);
char			*pflagh(t_occurrence *occ);
char			*pflags(t_occurrence *occ);
int				pfield_width(t_occurrence *occ);
#endif
