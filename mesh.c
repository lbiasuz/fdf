/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:52:56 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/10/02 22:30:11 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mesh	*init_mesh(int fd)
{
	t_mesh	*mesh;

	mesh = init_statics();
	mesh->grid = read_mesh(fd, 0, 0, mesh->size_scale);
	mesh->arr_x = array_size(mesh->grid[0]);
	mesh->arr_y = arr_arr_size(mesh->grid);
	mesh->mlx = mlx_init();
	mesh->mlx_win = mlx_new_window(
			mesh->mlx, mesh->size_x, mesh->size_y, "FDF?"
			);
	mesh->image = mlx_new_image(mesh->mlx, mesh->size_x, mesh->size_y);
	mesh->image_str = mlx_get_data_addr(
			mesh->image, &mesh->bpp, &mesh->line_size, &mesh->endianes
			);
	return (mesh);
}

t_mesh	*init_statics(void)
{
	t_mesh	*mesh;

	mesh = malloc(sizeof(t_mesh));
	mesh->bpp = 32;
	mesh->endianes = 0;
	mesh->size_scale = 20;
	mesh->size_x = 1200;
	mesh->size_y = 1000;
	mesh->line_size = 1200;
	mesh->angle = -30;
	mesh->x_offset = 0;
	mesh->y_offset = 0;
	return (mesh);
}

void	iterate_mesh(t_mesh *mesh, void (*f)(t_point *, t_mesh *))
{
	int	iy;
	int	ix;

	iy = 0;
	ix = 0;
	while (mesh->grid[iy])
	{
		while (mesh->grid[iy][ix])
		{
			f(mesh->grid[iy][ix], mesh);
			ix++;
		}
		ix = 0;
		iy++;
	}
}
