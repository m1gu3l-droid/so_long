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

#MLX = ./minilibx-linux

RM = rm -f

SO_LONG = so_long

SRC = so_long.c map_validation/read_map.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c gnl/get_height.c gnl/get_width.c \
	gnl/ft_strchr_gnl.c

OBJ = $(SRC:.c=.o)

all: $(SO_LONG)

$(LIBFT):
	$(MAKE) -C ./libft

#$(MLX):
#	$(MAKE) -C ./minilibx-linux

$(SO_LONG): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o so_long

clean:
	$(MAKE) clean -C ./libft
#	$(MAKE) clean -C ./minilibx-linux
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(SO_LONG)

re: clean fclean all

.SILENT:
