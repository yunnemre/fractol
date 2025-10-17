CC        = cc
CFLAGS    = -Wall -Wextra -Werror -Iincludes -Iminilibx-linux -Ilibft
RM        = rm -rf

NAME      = fractol

LIBFT_DIR = libft
LIBFT_A   = $(LIBFT_DIR)/libft.a

MLX_DIR   = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

SRC_DIR   = src
OBJ_DIR   = obj

SRCS      = $(SRC_DIR)/main.c \
            $(SRC_DIR)/init.c \
            $(SRC_DIR)/math_utils.c \
            $(SRC_DIR)/render.c \
            $(SRC_DIR)/window_utils.c \
            $(SRC_DIR)/window_events.c \
            $(SRC_DIR)/utils.c \
            $(SRC_DIR)/fract_shitf.c \
            $(SRC_DIR)/create_palete.c \
            $(SRC_DIR)/julia_mlx.c \
            $(SRC_DIR)/jul_win_utils.c \
            $(SRC_DIR)/helper.c \
            $(SRC_DIR)/power_calc.c

OBJS      = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(MLX_FLAGS) -o $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c includes/fractol.h | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus