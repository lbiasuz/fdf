# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 20:22:21 by lbiasuz           #+#    #+#              #
#    Updated: 2022/08/23 22:57:42 by lbiasuz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	gcc

io:
	$(CC) teste.c minilibx/libmlx_Linux.a libft/libft.a -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g3