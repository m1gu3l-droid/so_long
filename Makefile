# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 04:17:23 by fnovais-          #+#    #+#              #
#    Updated: 2023/06/03 04:25:55 by fnovais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

GNL = ./get_next_line/gnl.a

RM = rm -f

SO_LONG = so_long

SRC = so_long.c

OBJ = $(SRC:.c=.o)

all: $(SO_LONG)

$(LIBFT):
	$(MAKE) -C ./libft

$(GNL):
	$(MAKE) -C ./get_next_line

$(SO_LONG): $(OBJ) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(GNL) -o so_long

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./get_next_line
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./get_next_line
	$(RM) $(SO_LONG)

re: clean fclean all

.SILENT:
