NAME = ft_ls 

CFLAGS = -Wall -Wextra -Werror

HEADERS = 	fillit.h\
			libft/libft.h\

LIB = libft/

SOURCES = 	srcs/main.c\
			srcs/ft_valid_input.c\
			srcs/ft_get_dir.c\
			srcs/ft_display.c\
			srcs/ft_sort_tabs.c\
			srcs/is_before.c\

OBJECT = $(SOURCES:.c=.o)

$(NAME): $(LIB) $(OBJECT)
		make -C libft/
		gcc -o $(NAME) $(CFLAGS) $(OBJECT) libft/libft.a -L./libft/

all: $(NAME)

clean:
		rm -rf $(OBJECT)
		make -C libft clean

fclean: clean
		rm -rf $(NAME)
		make -C libft fclean

re: fclean all
