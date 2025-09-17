NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra -I./include -I./libft

SRC = ./src/main.c \
	./src/events.c \
	./src/init.c \
	./src/utils.c \
	./src/render.c \
	./src/cleanup.c \
	./src/fractal_sets.c \
	./src/colors.c \
	./src/render_fractals.c \
	./src/render_bifurcation.c

OBJ = $(SRC:.c=.o)

MLX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm -lz

LIBFT = ./libft/libft.a

all: $(NAME)

$(LIBFT) :
	$(MAKE) -C ./libft/

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./libft/ clean

fclean:
	rm -f $(OBJ) $(NAME)
	$(MAKE) -C ./libft/ fclean

re: fclean all

.PHONY: all clean fclean re
