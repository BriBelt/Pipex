NAME = pipex

SRCS = pipex.c \
	   libft_utils.c \
	   libft_utils2.c \
	   ft_split.c \
	   ft_strlen.c

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS += -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
