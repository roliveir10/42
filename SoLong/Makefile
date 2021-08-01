NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibft -lft -Lminilibx -lmlx -framework OpenGL -framework AppKit

INC_LINK = -I $(INC_LIBFT) -I $(INC_DIR) -I $(INC_MLX) 

SRC_DIR = srcs
SRC =	main.c						\
		solong_manager.c			\
		solong_map.c				\
		solong_display.c			\
		solong_mlx.c				\
		solong_event.c				\
		solong_player.c				\
		solong_consomable.c			\
		solong_gameover.c			\
		solong_ennemy.c				\
		solong_texture.c

INC_DIR = includes
INC_MLX = minilibx
INC_LIBFT = libft


OBJ_DIR = .o
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR)/,$(OBJ))
	make -C libft
	make -C minilibx
	$(CC) $(CFLAGS) $(INC_LINK) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC_LINK) -o $@ -c $<

$(OBJ_DIR):
	mkdir $@

clean:
	make -C libft clean
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	make -C libft fclean
	make -C minilibx clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
