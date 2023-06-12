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
	src/read_map.c src/start_position.c src/render_img.c \
	src/access_img.c src/closure.c src/control_key.c \
	src/free_ft.c src/validations.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c gnl/get_dimensions.c \
	gnl/ft_strchr_gnl.c

OBJ = $(SRC:.c=.o)
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

re: clean fclean all

.SILENT:
