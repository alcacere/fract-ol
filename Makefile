GREEN = "\033[32m"
RESET = "\033[0m"

NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra -I./include -I./libft

SRC = ./src/colors/colors.c \
	./src/events/events.c \
	./src/fractal_sets/fractal_sets.c \
	./src/init/init.c \
	./src/main/main.c \
	./src/renders/render_bifurcation.c \
	./src/renders/render.c \
	./src/renders/render_fractals.c \
	./src/utils/cleanup.c \
	./src/utils/utils.c


OBJ = $(SRC:.c=.o)

MLX_PATH = ./minilibx-linux/

MLX = $(MLX_PATH)libmlx_Linux.a

MLX_FLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm -lz

LIBFT_PATH = ./libft/

LIBFT = $(LIBFT_PATH)libft.a

all: $(NAME)

$(LIBFT) :
	@echo $(GREEN)"COMPILING LIBFT" $(RESET)
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX) :
	@echo $(GREEN)"COMPILING MINILIBX" $(RESET)
	@$(MAKE) -C $(MLX_PATH)
%.o: %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(LIBFT) $(MLX) $(OBJ)
	@echo $(GREEN)"COMPILING FRACTOL BINARY" $(RESET)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

clean:
	@echo $(GREEN)"CLEANING UP OBJECTS" $(RESET)
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean

fclean:
	@echo $(GREEN)"CLEANING UP OBJECTS AND BINARIES" $(RESET)
	@rm -f $(OBJ) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re
