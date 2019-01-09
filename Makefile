NAME = ft_ls 

CFLAGS = -Wall -Wextra -Werror

HEADERS = 	fillit.h\
			libft/libft.h\

LIB = libft/

SOURCES = 	srcs/main.c\
			srcs/ft_valid_input.c\
			srcs/ft_get_dir.c\

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
