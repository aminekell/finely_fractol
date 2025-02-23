# Compiler & Flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O3

# Directories
MANDATORY_DIR	= source/Mandatory
BONUS_DIR		= source/Bonus
INCLUDE_DIR		= source/Include

# Library Paths
MLX_DIR		= minilibx
LIBFT_DIR	= $(INCLUDE_DIR)/libft
PRINTF_DIR	= $(INCLUDE_DIR)/ft_printf

# Libraries
MLX_LIB		= $(MLX_DIR)/libmlx.a
LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF		= $(PRINTF_DIR)/libftprintf.a

# MiniLibX Flags
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm -O3

# Source Files
MANDATORY_SRC	= $(MANDATORY_DIR)/main.c \
				  $(MANDATORY_DIR)/julia.c \
				  $(MANDATORY_DIR)/init.c \
				  $(MANDATORY_DIR)/draw.c \
				  $(MANDATORY_DIR)/utils.c \
				  $(MANDATORY_DIR)/mandelbrot.c \
				  $(MANDATORY_DIR)/mouse_and_keys.c \
				  $(MANDATORY_DIR)/is_valid_float.c

BONUS_SRC	= $(BONUS_DIR)/bonus_draw.c \
			  $(BONUS_DIR)/bonus_init.c \
			  $(BONUS_DIR)/bonus_julia.c \
			  $(BONUS_DIR)/bonus_mandelbrot.c \
			  $(BONUS_DIR)/bonus_mouse_and_keys.c \
			  $(BONUS_DIR)/bonus_tricorn.c \
			  $(BONUS_DIR)/bonus_utils.c \
			  $(BONUS_DIR)/is_valid_float_bonus.c \
			  $(BONUS_DIR)/draw_fractal_bonus.c \
			  $(BONUS_DIR)/main_bonus.c

# Object Files
MANDATORY_OBJS	= $(MANDATORY_SRC:.c=.o)
BONUS_OBJS		= $(BONUS_SRC:.c=.o)

# Headers
INCLUDES	= -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR)

# Binary Names
NAME		= fractol
BONUS_NAME	= fractol_bonus

# Compilation Rules
all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(MANDATORY_OBJS) $(LIBFT) $(PRINTF) $(MLX_LIB)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) $(MLX_FLAGS) $(LIBFT) $(PRINTF) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(PRINTF) $(MLX_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX_FLAGS) $(LIBFT) $(PRINTF) -o $(BONUS_NAME)

# Compilation with dependencies
./source/Mandatory/%.o: ./source/Mandatory/%.c ./source/Include/fractol.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

./source/Bonus/%.o: ./source/Bonus/%.c ./source/Include/fractol_bonus.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Library Compilation
$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

# Clean Rules
clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
