CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = free_memory.c parsing_opera.c push_swap.c sorting_small.c \
       ps_helper.c stack_opera.c sorting_big.c ft_substr.c ft_split.c \
       quicksort.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
