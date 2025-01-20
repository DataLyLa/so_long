NAME = libftprintf.a

FILES = ft_printf.c \
		ft_print_i.c \
		ft_print_p.c \
		ft_print_u.c \
		ft_print_x.c \
		libft_printf/ft_absolute.c \
		libft_printf/ft_putc.c \
		libft_printf/ft_puts.c \
		libft_printf/ft_putn_ulli.c\
		libft_printf/ft_putn_ui.c\
		libft_printf/ft_putn_i.c\

CC = cc
C_FLAGS = -Wall -Werror -Wextra -fPIC

OBJS = $(FILES:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re