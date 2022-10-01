# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 20:22:21 by lbiasuz           #+#    #+#              #
#    Updated: 2022/10/01 16:37:30 by lbiasuz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=				gcc

NAME	=			fdf.out

HEAD_FILES	=		fdf.h

OPTIONS		=		-Wall -Wextra -Werror -Lmlx_linux \
					-L/usr/lib -Imlx_linux -lXext -lX11 \
					-lm -lz -g3

DEPENDENCIES	=	minilibx.a libft.a

SRC_FILES		=	free.c read_mesh.c plot_mesh.c dot_fdf.c fdf.c \
					helper_functions.c mesh.c line.c hooks.c point.c

OBJ_FILES		= $(SRC_FILES:.c=.o)

all: $(NAME)

$(DEPENDENCIES):
	make -C libft/
	mv libft/libft.a libft.a
	make -C minilibx/
	mv minilibx/libmlx.a minilibx.a

$(NAME): $(DEPENDENCIES)
	$(CC) $(SRC_FILES) $(DEPENDENCIES) $(OPTIONS)

clean:
	make -C libft/ clean
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf libft.a minilibx.a fdf

io:
	$(CC) teste.c minilibx.a libft.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g3
