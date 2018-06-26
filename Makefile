# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgricour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 11:10:43 by kgricour          #+#    #+#              #
#    Updated: 2018/06/26 20:31:28 by cholm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = bres.c key_events.c parser.c main.c error.c
LIB = ./libft
LIB_A = libft.a
FLAG = -Wall -Werror -Wextra
FLAGMLX = -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	gcc -c $(FLAG) $<
$(NAME): $(OBJ) $(LIB)
	make -C $(LIB)
	make -C minilibx_macos
	gcc $(FLAG) $(FLAGMLX) $(OBJ) $(LIB)/$(LIB_A) minilibx_macos/libmlx.a -o $(NAME)

clean:
	make clean -C $(LIB)
	make clean -C minilibx_macos
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME) $(LIB)/$(LIB_A)

re: fclean all

.PHONY: all clean fclean re
