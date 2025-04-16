CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	free_memory.c \
		parsing_opera.c \
		push_swap.c \
		sorting_small.c \
       	ps_helper.c \
       	stack_opera.c \
       	ft_substr.c \
       	ft_split.c \
       	sort_500_100.c \
       	sorting_utils.c \

BONUS_SRC = bonus/checker.c \
			bonus/get_next_line.c \
			bonus/get_next_line_utils.c \
			bonus/free_memory_bonus.c \
			bonus/ft_split_bonus.c \
			bonus/ft_strncmp_bonus.c \
			bonus/parsing_opera_bonus.c \
			bonus/ps_helper_bonus.c \
			bonus/stack_opera_bonus_1.c \
			bonus/stack_opera_bonus_2.c \
			bonus/operations.c \

BONUS_OBJ = $(BONUS_SRC:.c=.o)
OBJS = $(SRCS:.c=.o)

NAME = push_swap
BONUS_NAME = checker

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
