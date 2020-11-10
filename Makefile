# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 17:17:43 by madan             #+#    #+#              #
#    Updated: 2020/11/07 19:50:17 by madan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fractol

CFLAGS =  -Wall -Wextra -Werror
GFLAGS =  -lmlx -framework OpenGL -framework AppKit

HEA_P = ./inc
HEA_F = fractol.h
HEA =   $(addprefix $(HEA_P)/, $(HEA_F))

SRC_P = ./src
SRC_F = brots.c \
   			draw.c \
            initial.c \
            mandelbrot.c \
            set_and_put.c \
            fractol.c \
            keys.c \
            zoom.c
SRC = 	$(addprefix $(SRC_P)/,$(SRC_F))

OBJ_P = ./src
OBJ_F = $(SRC_F:.c=.o)
OBJ = $(addprefix $(OBJ_P)/,$(OBJ_F))

all:    $(NAME)

$(NAME):    $(OBJ) $(HEA)
		@make -C libft
		@gcc $(CFLAGS) $(OBJ) $(GFLAGS) libft/libft.a -o $(NAME)

%.o:%.c     $(HEA)
		@gcc $(CFLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJ)
		@make -C libft clean

fclean:     clean
		@make -C libft fclean
		@rm -rf $(NAME)

re:     fclean all

.PHONY: all clean fclean re
