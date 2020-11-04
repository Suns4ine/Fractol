# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 17:17:43 by madan             #+#    #+#              #
#    Updated: 2020/10/31 17:18:10 by madan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC_P = ./src/
OBJ_P = ./

CFLAGS = -Wall -Wextra -Werror

LIBS = -lm -L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

HEADERS = $(SRC_P)fractol.h

SRC = brots.c \
			draw.c \
			initial.c \
			mandelbrot.c \
			set_and_put.c \
			fractol.c \
			keys.c \
			zoom.c

OBJ = $(addprefix $(SRC_P), $(SRC:.c=.o))

all:	$(NAME)

$(NAME):	$(OBJ) $(HEADERS)
			make -C minilibx_macos/
			make -C libft/
			gcc $(OBJ) -o $(NAME) $(LIBS)

clean:
			make -C libft/ clean
			rm -f $(OBJ)

mclean:
			make -C minilibx_macos/ clean

fclean:		clean
			make -C minilibx_macos/ clean
			make -C libft/ fclean
			rm -f $(NAME)

re:			fclean all
