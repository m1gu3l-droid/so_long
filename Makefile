# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 04:17:23 by fnovais-          #+#    #+#              #
#    Updated: 2023/06/25 23:07:55 by fnovais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

MLX = ./mlx/libmlx.a

RM = rm -f

SO_LONG = so_long

SO_LONG_BONUS = so_long_bonus

LIBFTFILES = libft/*c
SRC =	src/so_long.c src/read_map.c src/start_position.c src/render_sprite.c \
	src/access_sprite.c src/closure.c src/control_key.c \
	src/validations.c src/val_path.c\
	src/get_next_line.c src/get_next_line_utils.c src/get_dimensions.c \
	src/ft_strchr_gnl.c

SRC_BONUS = src_bonus/so_long_bonus.c src_bonus/access_sprite_bonus.c \
		src_bonus/control_key_bonus.c src_bonus/render_sprite_bonus.c \
		src_bonus/read_map_bonus.c src_bonus/start_position_bonus.c \
		src_bonus/closure_bonus.c src_bonus/validations_bonus.c \
		src_bonus/val_path_bonus.c src_bonus/get_next_line_bonus.c \
		src_bonus/get_next_line_utils_bonus.c src_bonus/animate.c \
		src_bonus/get_dimensions_bonus.c src_bonus/ft_strchr_gnl_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CCMLX = -L ./mlx -lmlx -Ilmlx -lXext -lX11

NONE='\033[0m'
CYAN='\033[0;36;49m'
YELLOW='\033[1;33m'
RED='\033[1;31;48m'
GREEN='\033[1;32m'
CURSIVE='\033[3m'

all: $(SO_LONG)

bonus: $(SO_LONG_BONUS)

$(LIBFT):
	@echo $(CURSIVE)$(YELLOW) "     - Making libft..." $(NONE)
	$(MAKE) -C ./libft

$(MLX):
	@echo $(CURSIVE)$(GRAY) "     - Making mlx..." $(NONE)
	$(MAKE) -C ./mlx

$(SO_LONG): $(OBJ) $(LIBFT) $(MLX)
	@echo $(CURSIVE)$(YELLOW) "     - Compiling $(SO_LONG)..." $(NONE)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(CCMLX) -o $(SO_LONG)
	@echo $(GREEN)"      - Compiled -"$(NONE)

$(SO_LONG_BONUS): $(OBJ_BONUS) $(LIBFT) $(MLX)
	@echo $(CURSIVE)$(YELLOW) "     - Compiling $(SO_LONG_BONUS)..." $(NONE)
	$(CC) $(CFLAGS) -pthread $(OBJ_BONUS) $(LIBFT) $(CCMLX) -o $(SO_LONG_BONUS) -pthread
	@echo $(GREEN)"      - Compiled -"$(NONE)

norm:
	@echo $(CYAN) ""
	@norminette $(SRC) $(LIBFTFILES) *.h
	@echo $(NONE) ""

norm_bonus:
	@echo $(CYAN) ""
	@norminette $(SRC_BONUS)
	@echo $(NONE) ""

clean:
	@echo $(CURSIVE)$(RED) "     - Removing object files..." $(NONE)
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)

fclean: clean
	@echo $(CURSIVE)$(RED) "     - Removing program..." $(NONE)
	$(MAKE) fclean -C ./libft
	$(RM) $(SO_LONG)
	$(RM) $(SO_LONG_BONUS)

re: clean fclean all

.SILENT:
