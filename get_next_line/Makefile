# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 12:53:40 by fnovais-          #+#    #+#              #
#    Updated: 2022/11/17 13:02:50 by fnovais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

CC = cc -g

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c get_height.c get_width.c ft_strchr_gnl.c

BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

BONUS_OBJ = $(BONUS:.c=.o)

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ) $(BONUS_OBJ)

fclean:		clean
		$(RM) $(NAME)

re: fclean $(NAME)

bonus: $(NAME) $(BONUS_OBJ)
			ar rcs $(NAME) $(BONUS_OBJ)
