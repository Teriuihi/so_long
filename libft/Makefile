NAME=libft.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
FILES=ft_contains.c ft_iswhite_space.c ft_memcpy.c ft_memset.c \
ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
ft_lstdelentry.c
GET_NEXT_LINE=get_next_line.c get_next_line_utils.c
FILES_OBJ=$(FILES:%.c=%.o) $(GET_NEXT_LINE:%.c=get_next_line/%.o)

all: $(NAME)

$(NAME): $(FILES_OBJ)
	ar -rcs $(NAME) $(FILES_OBJ)

clean:
	$(RM) $(FILES_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: make all clean fclean re
