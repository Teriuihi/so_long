NAME=so_long
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

FILES=main.c file_validation.c file_init.c game_start.c util.c draw.c \
listeners.c game_move.c
FILES_OBJ=$(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(FILES_OBJ)
	$(MAKE) -C libft/
	$(MAKE) -C mlx/
	cp mlx/libmlx.dylib .
	$(CC) $(CFLAGS) -o $(NAME) $(FILES_OBJ) libft/libft.a libmlx.dylib

clean:
	$(RM) $(FILES_OBJ)
	$(MAKE) -C libft/ clean
	$(MAKE) -C mlx/ clean

fclean: clean
	$(RM) $(NAME) libmlx.dylib
	$(MAKE) -C libft/ fclean
	$(MAKE) -C mlx/ fclean

re: fclean $(NAME)

.PHONY: make all clean fclean re
