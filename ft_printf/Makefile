NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT_FLAG = -Llibft -lft

SRCS =	ft_printf.c		\
		flag.c			\
		stack.c			\
		arg_cspdi.c		\
		arg_uxX.c		\
		flag_func.c		\
		precision.c

LIBFT = libft/libft.a

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	mv $(LIBFT) $@
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I libft

bonus: all

clean:
	/bin/rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: re fclean clean all
