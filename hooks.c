/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:11:03 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/10/02 21:38:59 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int key_code, t_mesh *mesh)
{
	if (key_code == XK_ESCAPE)
		close_fdf(mesh);
	else if (key_code == XK_Z || key_code == XK_X)
		handle_scale(key_code, mesh);
	else if (
		key_code == XK_W || key_code == XK_A
		|| key_code == XK_S || key_code == XK_D
	)
		handle_movement(key_code, mesh);
	// else if (key_code == XK_Q || key_code == XK_E)
	return (1);
}

int	handle_movement(int key_code, t_mesh *mesh)
{
	mlx_clear_window(mesh->mlx, mesh->mlx_win);
	ft_bzero(mesh->image_str, mesh->size_y * mesh->line_size);
	mesh->y_offset = 0;
	mesh->x_offset = 0;
	if (key_code == XK_W)
		mesh->y_offset -= 10 * mesh->size_scale;
	else if (key_code == XK_S)
		mesh->y_offset += 10 * mesh->size_scale;
	else if (key_code == XK_A)
		mesh->x_offset -= 10 * mesh->size_scale;
	else if (key_code == XK_D)
		mesh->x_offset += 10 * mesh->size_scale;
	iterate_mesh(mesh, move_point);
	return (1);
}

int	handle_scale(int key_code, t_mesh *mesh)
{
	mlx_clear_window(mesh->mlx, mesh->mlx_win);
	ft_bzero(mesh->image_str, mesh->size_y * mesh->line_size);
	if (key_code == XK_X && mesh->size_scale < 35)
		mesh->size_scale++;
	else if (key_code == XK_Z && mesh->size_scale > 7)
		mesh->size_scale--;
	iterate_mesh(mesh, refresh_point);
	iterate_mesh(mesh, center_point);
	iterate_mesh(mesh, move_point);
	iterate_mesh(mesh, rotate_point);
	return (1);
}

int	close_fdf(t_mesh *mesh)
{
	mlx_destroy_window(mesh->mlx, mesh->mlx_win);
	mlx_destroy_image(mesh->mlx, mesh->image);
	mlx_destroy_display(mesh->mlx);
	free_mesh(mesh);
	free(mesh->mlx);
	free(mesh);
	exit(0);
	return (0);
}
