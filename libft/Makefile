NAME=libft.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
FILES=ft_contains.c ft_iswhite_space.c ft_memcpy.c ft_memset.c \
ft_lstadd_back.c ft_lstclear.c ft_lstlast.c ft_lstnew.c ft_lstdelentry.c \
ft_lstdelone.c ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
ft_strlen.c ft_itoa.c ft_strtrim.c ft_strrchr.c ft_strlcpy.c ft_ends_with.c \
ft_strncmp.c
GET_NEXT_LINE=get_next_line.c get_next_line_utils.c
PRINTF=ft_printf.c hex.c hex_util.c printing.c
FILES_OBJ=$(FILES:%.c=%.o) $(GET_NEXT_LINE:%.c=get_next_line/%.o) $(PRINTF:%.c=ft_printf/%.o)

all: $(NAME)

$(NAME): $(FILES_OBJ)
	ar -rcs $(NAME) $(FILES_OBJ)

clean:
	$(RM) $(FILES_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: make all clean fclean re