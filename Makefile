NAME = pipex

SRCS = pipex.c \
	   pipex_utils.c \
	   children.c \
	   ft_split.c \
	   libft_utils.c \
	   libft_utils2.c

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS += -Wall -Wextra -Werror -g3 -fsanitize=address

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc  $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
