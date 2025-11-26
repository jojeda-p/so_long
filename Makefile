# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(MLX_DIR)
SRCS = src/main.c \
       src/map.c \
	   src/move_down.c \
	   src/move_left.c \
	   src/move_right.c \
	   src/error.c \
	   src/error2.c \
	   src/utils.c \
	   src/error3.c \
	   src/move_up.c \
	   src/print_map.c \
       src/path.c \
       src/get_next_line/get_next_line.c \
       src/get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
NAME = so_long
HEADER = include/so_long.h
GNL_HEADER = src/get_next_line/get_next_line.h
MLX = $(MLX_DIR)/libmlx.a
PRINTF_DIR = src/ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX_DIR = minilibx-linux
MLX_FLAGS = -L $(MLX_DIR) -lmlx -lX11 -lXext -lm -lbsd
PRINTF_FLAGS = -L $(PRINTF_DIR) -lftprintf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(PRINTF_FLAGS) -o $(NAME)
	@echo "$(GREEN)so_long compiled successfully!$(DEF_COLOR)"
	@echo "$(CYAN)"
	@echo "  ____        _                   "
	@echo " / ___|  ___ | | ___  _ __   __ _ "
	@echo " \___ \ / _ \| |/ _ \| '_ \ / _\` |"
	@echo "  ___) | (_) | | (_) | | | | (_| |"
	@echo " |____/ \___/|_|\___/|_| |_|\__, |"
	@echo "                            |___/ "
	@echo "          by jojeda-p"
	@echo "$(DEF_COLOR)"

$(MLX):
	@echo "$(YELLOW)Compiling MinilibX...$(DEF_COLOR)"
	@make -s -C $(MLX_DIR)

$(PRINTF):
	@echo "$(YELLOW)Compiling ft_printf...$(DEF_COLOR)"
	@make -s -C $(PRINTF_DIR)

%.o: %.c $(HEADER) $(GNL_HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -s -C $(PRINTF_DIR) clean
	@echo "$(BLUE)Object files cleaned!$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@make -s -C $(PRINTF_DIR) fclean
	@echo "$(CYAN)Executables cleaned!$(DEF_COLOR)"

re: fclean all
