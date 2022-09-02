/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:23:52 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/09/01 22:50:11 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"
# include "minilibx/mlx.h"
# include <fcntl.h>

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
	void	*image;
	int		size_x;
	int		size_y;
	t_list	*grid;
} t_mesh;

int		open_fdf(char *file_name);
void	free_point(t_point *point);
void	free_line(void *list);
void	free_mesh(t_mesh *mesh);
void	free_arr(char **arr);

void	put_pixel(t_point point, t_mesh *mesh);
void	plot_line(t_point *beg, t_point *end, t_mesh *mesh);
void	plot_mesh(t_mesh *mesh);

int		atoh(char *hex_string);
t_point	*new_point(int x, int y, char *z_color);
t_list	*get_line_split(char *line, int x, int y);
t_list	*read_mesh(int fd);

#endif