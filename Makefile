CC      = cc
CFLAGS  = 
RM      = rm -rf

SRCS    = main.c \
		  init.c \
		  math_utils.c \
		  render.c \
		  window_utils.c \
		  ft_err_man.c \
		  
OBJS    = $(SRCS:.c=.o)

NAME    = fractol
LIBFT_DIR = libft
LIBFT_A   = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux/./minilibx-linux
MLX = $(MLX_DIR)/libmlx.a -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm

all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
