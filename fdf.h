/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:23:52 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/10/03 07:52:03 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define XK_ESCAPE 65307
# define XK_Z 122
# define XK_X 120
# define XK_W 119
# define XK_A 97
# define XK_S 115
# define XK_D 100
# define XK_Q 113
# define XK_E 101
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_point {
	int	x;
	int	y;
	int	z;
	int	color;
	int	px;
	int	py;
}	t_point;

typedef struct s_mesh {
	void	*mlx;
	void	*mlx_win;
	char	*image_str;
	void	*image;
	int		arr_x;
	int		arr_y;
	int		size_x;
	int		size_y;
	int		line_size;
	int		size_scale;
	t_point	***grid;
	int		bpp;
	int		endianes;
	double	angle;
	int		y_offset;
	int		x_offset;
}	t_mesh;

int		open_fdf(char *file_name);
void	free_point(t_point *point);
void	free_line(void *list);
void	free_mesh(t_mesh *mesh);
void	free_arr(char **arr);
int		close_fdf(t_mesh *mesh);

int		handle_keypress(int key_code, t_mesh *mesh);
int		handle_scale(int key_code, t_mesh *mesh);
int		handle_rotate(int key_code, t_mesh *mesh);
int		handle_movement(int key_code, t_mesh *mesh);

void	put_pixel(t_point point, t_mesh *mesh);
void	plot_line(t_point *beg, t_point *end, t_mesh *mesh);
void	plot_line_x(t_point *beg, t_point *end, t_mesh *mesh);
void	plot_line_nx(t_point *beg, t_point *end, t_mesh *mesh);
void	plot_line_y(t_point *beg, t_point *end, t_mesh *mesh);
void	plot_line_ny(t_point *beg, t_point *end, t_mesh *mesh);
void	plot_mesh(t_mesh *mesh);

t_mesh	*init_statics(void);
t_mesh	*init_mesh(int fd);
void	move_point(t_point *point, t_mesh *mesh);
void	center_point(t_point *point, t_mesh *mesh);
void	rotate_point(t_point *point, t_mesh *mesh);
void	refresh_point(t_point *point, t_mesh *mesh);
void	iterate_mesh(t_mesh *mesh, void (*f)(t_point *, t_mesh *));

int		ft_abs(int n);
int		atoh(char *hex_string);
t_point	*new_point(int x, int y, char *z_color, int size_scale);
t_point	**get_line_split(char *line, int x, int y, int size_scale);
t_point	***read_mesh(int fd, int x, int y, int size_scale);

int		array_size(t_point **list);
int		arr_arr_size(t_point ***list);

#endif
