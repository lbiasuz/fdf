/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:11:03 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/08/27 16:39:53 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_close(int key_code, t_mesh *mesh)
{
	if (key_code == XK_Escape)
	{
		mlx_destroy_window(mesh->mlx, mesh->mlx_win);
		mlx_destroy_image(mesh->mlx, mesh->image);
		mlx_destroy_display(mesh->mlx);
		free_mesh(mesh);
		free(mesh->mlx);
		free(mesh);
		exit(0);
	}
	return (0);
}

int	handle_scale(int key_code, t_mesh *mesh)
{
	mlx_clear_window(mesh->mlx, mesh->mlx_win);
	ft_bzero(mesh->image_str, mesh->size_y * mesh->line_size);	
	if (key_code == XK_Up)
		mesh->size_scale++;
	else if (key_code == XK_Down)
		mesh->size_scale--;
	iterate_mesh(mesh, refresh_point);
	iterate_mesh(mesh, center_point);
	iterate_mesh(mesh, rotate_point);
	return (1);
}
