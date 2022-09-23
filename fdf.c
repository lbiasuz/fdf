/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:37:37 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/09/01 23:41:42 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_mesh(void *aux)
{	

	t_mesh		*mesh;

	mesh = (t_mesh *) aux;
	plot_mesh(mesh);
	mlx_put_image_to_window(mesh->mlx, mesh->mlx_win, mesh->image, 0, 0); 
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	
	t_mesh	*mesh;
	if (argc <= 1)
		return (0);
	ft_printf("FD: %s \n", argv[1]);
	fd = open_fdf(argv[1]);
	if (fd <= 0)
		return (0);
	mesh = malloc(sizeof(t_mesh));
	mesh->size_scale = 25;
	mesh->grid = read_mesh(fd, 0, 0, mesh->size_scale);
	mesh->arr_x = array_size(mesh->grid[0]);
	mesh->arr_y = arr_arr_size(mesh->grid);
	mesh->size_x = 1200; 
	mesh->size_y = 1000; 
	mesh->angle = -30 * 3.1415f / 180; 
	iterate_mesh(mesh, center_point);
	iterate_mesh(mesh, rotate_point);
	mesh->bpp = 32;
	mesh->endianes = 0;
	mesh->mlx = mlx_init();
	mesh->mlx_win = mlx_new_window(mesh->mlx, mesh->size_x, mesh->size_y, "FDF?");
	mesh->image = mlx_new_image(mesh->mlx, mesh->size_x, mesh->size_y);
	mesh->image_str = mlx_get_data_addr(mesh->image, &mesh->bpp, &mesh->size_x, &mesh->endianes);
	mlx_loop_hook(mesh->mlx, print_mesh, mesh);
	mlx_loop(mesh->mlx);
	close(fd);
}

