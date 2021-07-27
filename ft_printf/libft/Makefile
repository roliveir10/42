NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	btree_apply_infix.c			\
		btree_apply_prefix.c		\
		btree_apply_suffix.c		\
		btree_create_node.c			\
		btree_insert_data.c			\
		btree_level_count.c			\
		btree_search_item.c			\
		ft_abs.c					\
		ft_atoi.c					\
		ft_atoi_base.c				\
		ft_atoip.c					\
		ft_bzero.c					\
		ft_calloc.c					\
		ft_check_base.c				\
		ft_clamp.c					\
		ft_del_words_tables.c		\
		ft_filedup.c				\
		ft_filejoin.c				\
		ft_is_prime.c				\
		ft_isalnum.c				\
		ft_isalpha.c				\
		ft_isascii.c				\
		ft_isdigit.c				\
		ft_islowercase.c			\
		ft_isprint.c				\
		ft_isspace.c				\
		ft_isuppercase.c			\
		ft_itoa.c					\
		ft_itoa_base.c				\
		ft_line.c					\
		ft_list_at.c				\
		ft_list_clear.c				\
		ft_list_create_elem.c		\
		ft_list_del_one.c			\
		ft_list_find.c				\
		ft_list_iter.c				\
		ft_list_last.c				\
		ft_list_map.c				\
		ft_list_merge.c				\
		ft_list_push_back.c			\
		ft_list_push_front.c		\
		ft_list_push_strs.c			\
		ft_list_remove_if.c			\
		ft_list_reverse.c			\
		ft_list_size.c				\
		ft_list_sort.c				\
		ft_max.c					\
		ft_memccpy.c				\
		ft_memchr.c					\
		ft_memcmp.c					\
		ft_memcpy.c					\
		ft_memdel.c					\
		ft_memmove.c				\
		ft_memset.c					\
		ft_min.c					\
		ft_nbrlen.c					\
		ft_pow.c					\
		ft_print_digit.c			\
		ft_print_digit_tables.c		\
		ft_print_words_tables.c		\
		ft_putchar.c				\
		ft_putchar_fd.c				\
		ft_putendl.c				\
		ft_putendl_fd.c				\
		ft_putnbr.c					\
		ft_putnbr_base.c			\
		ft_putnbr_fd.c				\
		ft_putnbrl.c				\
		ft_putstr.c					\
		ft_putstr_fd.c				\
		ft_putstr_non_printable.c	\
		ft_sort_int_tab.c			\
		ft_sorted_list_insert.c		\
		ft_sorted_list_merge.c		\
		ft_split.c					\
		ft_sqrt.c					\
		ft_str_is_alpha.c			\
		ft_str_is_lowercase.c		\
		ft_str_is_numeric.c			\
		ft_str_is_printable.c		\
		ft_str_is_uppercase.c		\
		ft_strcat.c					\
		ft_strchr.c					\
		ft_strcmp.c					\
		ft_strcpy.c					\
		ft_strdel.c					\
		ft_strdup.c					\
		ft_striteri.c				\
		ft_strjoin.c				\
		ft_strjoinf.c				\
		ft_strlcat.c				\
		ft_strlcpy.c				\
		ft_strlen.c					\
		ft_strlowcase.c				\
		ft_strmapi.c				\
		ft_strncat.c				\
		ft_strncmp.c				\
		ft_strncpy.c				\
		ft_strndup.c				\
		ft_strnstr.c				\
		ft_strrchr.c				\
		ft_strrev.c					\
		ft_strstr.c					\
		ft_strtrim.c				\
		ft_strupcase.c				\
		ft_substr.c					\
		ft_swap.c					\
		ft_swap_char.c				\
		ft_swap_int.c				\
		ft_swap_str.c				\
		ft_tolower.c				\
		ft_toupper.c				\
		ft_uatoi.c					\
		ft_uitoa_base.c				\
		ft_vadd.c					\
		ft_vcross.c					\
		ft_vdist.c					\
		ft_vdiv.c					\
		ft_vdot.c					\
		ft_vdot_to_vector3.c		\
		ft_vmul.c					\
		ft_vnormalize.c				\
		ft_vsub.c

	
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
