# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 20:22:21 by lbiasuz           #+#    #+#              #
#    Updated: 2022/08/27 23:42:53 by lbiasuz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=				gcc

NAME	=			fdf

HEAD_FILES	=		fdf.h

OPTIONS		=		-Wall -Wextra -Werror -Lmlx_linux \
					-L/usr/lib -Imlx_linux -lXext -lX11 \
					-lm -lz -g3

DEPENDENCIES	=	minilibx.a libft.a

SRC_FILES		=	free.c read_mesh.c

all: $(NAME)

$(DEPENDENCIES):
	make -C libft/
	cp libft/libft.a libft.a
	make -C minilibx/
	cp minilibx/libmlx_Linux.a minilibx.a

$(NAME): $(DEPENDENCIES)
	$(CC) $(OPTIONS) -c $(SRC_FILES) $(DEPENDENCIES)

io:
	$(CC) teste.c minilibx/libmlx_Linux.a libft/libft.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g3