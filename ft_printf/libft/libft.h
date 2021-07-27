#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define BUFF_SIZE 4096000

int				ft_atoi(const char *str);
int				ft_atoip(const char *str, int *i);
int				ft_atoi_base(const char *str, const char *base);
int				ft_check_base(const char *base);
char			*ft_filejoin(char const *s1, char const *s2,
					int n1, int n2);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_islowercase(int c);
int				ft_isspace(int c);
int				ft_isuppercase(int c);
char			*ft_itoa(long long n);
char			*ft_itoa_base(long long nbr, char *base_to);
char			*ft_line(int fd, char c);
int				ft_nbrlen(long long nb);
void			ft_sort_int_tab(int *tab, int size);
void			ft_swap(void **a, void **b);
void			ft_swap_char(char *a, char *b);
void			ft_swap_int(int *a, int *b);
void			ft_swap_str(char **a, char **b);
int				ft_toupper(int c);
unsigned int	ft_uatoi(const char *str);
char			*ft_uitoa_base(unsigned long long nbr, char *base_to);

/*
**	MEM
*/

void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			ft_del_words_tables(char ***tab);
char			*ft_filedup(int fd, int *size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);

/*
** STR
*/

char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdel(char **str);
char			*ft_strdup(const char *s1);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoinf(char **s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strlowcase(char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *dst, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrev(char *str);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strupcase(char *str);
int				ft_str_is_alpha(char *str);
int				ft_str_is_lowercase(char *str);
int				ft_str_is_numeric(char *str);
int				ft_str_is_printable(char *str);
int				ft_str_is_uppercase(char *str);
char			**ft_split(char const *s, char const *charset);
char			*ft_substr(char const *s, unsigned int start, size_t len);

/*
**	PRINTABLE
*/

void			ft_print_digit(int *tab, int size);
void			ft_print_digit_tables(int **mat, int x, int y);
void			ft_print_words_tables(char **tab);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char *str);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbrl(int nbr);
void			ft_putnbr_base(int nbr, const char *base);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char *str);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr_non_printable(char *str);

/*
**	LIST
*/

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

t_list			*ft_list_at(t_list *begin_list, unsigned int nbr);
void			ft_list_clear(t_list **lst, void (*del)(void *));
t_list			*ft_list_create_elem(void *data);
void			ft_list_del_one(t_list *lst, void (*del)(void *));
t_list			*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
void			ft_list_iter(t_list *lst, void (*f)(void *));
t_list			*ft_list_last(t_list *begin_list);
t_list			*ft_list_map(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void			ft_list_push_back(t_list **begin_list, void *data);
void			ft_list_push_front(t_list **begin_list, void *data);
t_list			*ft_list_push_strs(int size, char **strs);
void			ft_list_remove_if(t_list **begin_list, void *data_ref,
					int (*cmp)(), void (*free_fct)(void *));
void			ft_list_reverse(t_list *begin_list);
int				ft_list_size(t_list *begin_list);
void			ft_list_sort(t_list **begin_list, int (*cmp)());
void			ft_sorted_list_insert(t_list **begin_list, void *data,
					int (*cmp)());
void			ft_sorted_list_merge(t_list **begin_list1,
					t_list *begin_list2, int (*cmp)());
/*
**	MATHS
*/

unsigned int	ft_abs(int value);
int				ft_is_prime(int nb);
int				ft_sqrt(int nb);
int				ft_pow(int nb, int power);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				ft_clamp(int value, int lo, int hi);

/*
** BTREE
*/

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}				t_btree;

void			btree_apply_infix(t_btree *root, void (*applyf)(void *));
void			btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void			btree_apply_suffix(t_btree *root, void (*applyf)(void *));
t_btree			*btree_create_node(void *item);
void			btree_insert_data(t_btree **root, void *item,
					int (*cmpf)(void *, void *));
void			*btree_search_item(t_btree *root, void *data_ref,
					int (*cmpf)(void *, void *));
int				btree_level_count(t_btree *root);

/*
**	VECTOR
*/

typedef struct s_vector3
{
	double			x;
	double			y;
	double			z;
}					t_vector3;

t_vector3		ft_vadd(t_vector3 v1, t_vector3 v2);
t_vector3		ft_vcross(t_vector3 v1, t_vector3 v2);
double			ft_vdist(t_vector3 v1, t_vector3 v2);
t_vector3		ft_vdiv(t_vector3 v, double f);
double			ft_vdot(t_vector3 v1, t_vector3 v2);
t_vector3		ft_vdot_to_vector3(t_vector3 pos_a, t_vector3 pos_b);
t_vector3		ft_vmul(t_vector3 v, double f);
t_vector3		ft_vnormalize(t_vector3 v);
t_vector3		ft_vsub(t_vector3 v1, t_vector3 v2);
t_vector3		ft_vvmul(t_vector3 v1, t_vector3 v2);

#endif
