# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 04:17:23 by fnovais-          #+#    #+#              #
#    Updated: 2023/06/09 21:21:00 by fnovais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

MLX = ./mlx/libmlx.a

RM = rm -f

SO_LONG = so_long

SRC = so_long.c \
	src/read_map.c src/start_position.c src/render_sprite.c \
	src/access_sprite.c src/closure.c src/control_key.c \
	src/validations.c src/val_path.c\
	gnl/get_next_line.c gnl/get_next_line_utils.c gnl/get_dimensions.c \
	gnl/ft_strchr_gnl.c

SRC_BONUS = so_long_bonus.c src_bonus/access_sprite_bonus.c \
		src_bonus/control_key_bonus.c src_bonus/render_sprite_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CCMLX = -L ./mlx -lmlx -Ilmlx -lXext -lX11

all: $(SO_LONG)

$(LIBFT):
	$(MAKE) -C ./libft

$(MLX):
	$(MAKE) -C ./mlx

$(SO_LONG): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(CCMLX) -o so_long

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(SO_LONG)
	$(RM) so_long_bonus

re: clean fclean all

bonus: $(OBJ) $(OBJ_BONUS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_BONUS) $(LIBFT) $(CCMLX) -o so_long_bonus

.SILENT:
