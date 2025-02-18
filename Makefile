CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = algo_small_numbers.c first_algo_steps.c list_func.c push_swap.c sort.c utils1.c cleanup.c \
libft_helpers.c  parser_utils.c stack_func.c stack_func1.c stack_func2.c moves_utils.c algo_helpers.c libft_helpers1.c list_func1.c \
algo_helpers1.c get_next_line.c get_next_line_utils.c checker_utils.c

SRCS1 = algo_small_numbers.c first_algo_steps.c list_func.c sort.c utils1.c cleanup.c \
libft_helpers.c  parser_utils.c stack_func.c stack_func1.c stack_func2.c moves_utils.c algo_helpers.c libft_helpers1.c list_func1.c \
algo_helpers1.c get_next_line.c get_next_line_utils.c checker.c checker_utils.c utils1.c
OBJS = $(SRCS:.c=.o)
OBJS1 = $(SRCS1:.c=.o)
NAME = push_swap
NAME1 = checker

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME1)

$(NAME1): $(OBJS1)
	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -f $(OBJS) $(OBJS1)

fclean: clean
	rm -f $(NAME) $(NAME1)

re: fclean all

.PHONY: all clean fclean re bonus