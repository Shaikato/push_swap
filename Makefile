NAME = push_swap
SRCS = errors.c \
		init.c \
		lst_utils.c \
		push_swap.c \
		push.c \
		rev_rotate.c \
		rotate.c \
		sort_three.c \
		sort_utils.c \
		sort.c \
		stack_utils.c \
		swap.c \
		sort_commands.c

OBJS = ${SRCS:.c=.o}
PRINTF = ft_printf/libftprintf.a
LIBFT = libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	make -C ft_printf
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME)

clean:
	make clean -C ft_printf
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ft_printf
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean $(NAME)