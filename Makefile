NAME = fdf

SRCS = main.c check_file.c draw.c pixel_put.c get_next_line.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADER = -I./

FLAG_MLX = -L/usr/local/lib/ -I/usr/local/include -lm -lmlx -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	@make re -C ./libft/
	@echo "\033[1m\033[32m[ ✔ ]Compilation succes :\033[0m libft"
	@gcc -o $(NAME) $(SRCS) $(HEADER) $(FLAG_MLX) $(LIBFT)
	@echo "\033[1m\033[32m[ ✔ ]Compilation succes :\033[0m $(NAME)"

clean :
	@rm -f $(OBJ)
	@echo "\033[1m\033[31m[ ✔ ]Deleting succes :\033[0m OBJS"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[1m\033[31m[ ✔ ]Deleting succes :\033[0m $(NAME)"

re : fclean all
