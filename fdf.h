/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:23:52 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/08/27 09:46:40 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_point {
	int	x;
	int	y;
	int	z;
	int	color;
} t_point;

typedef struct s_mesh {
	void	*mlx;
	void	*mlx_win;
	char	*image_str;
	int		size_x;
	int		size_y;
	t_list	*grid;
} t_mesh;

#endif