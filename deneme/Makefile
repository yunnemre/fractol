NAME = fract
CC = gcc
CFLAGS =  -I./includes -I./libft
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = main.c \
      init.c \
      render_slice.c \
      win_signal.c \
      math.c \
	  utils.c
      

OBJ = $(SRC:.c=.o)

LIBFT = ../libft/libft.a
MLX_DIR = minilibx-linux
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all clean fclean re
