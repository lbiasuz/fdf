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

	int		endianes;
	int		bpp;
	t_mesh		*mesh;

	endianes = 1;
	bpp = 32;
	mesh = (t_mesh *) aux;
	mesh->image = mlx_new_image(mesh->mlx, mesh->size_x, mesh->size_y);
	mesh->image_str = mlx_get_data_addr(mesh->image, &bpp, &mesh->size_x, &endianes);
	//plot_mesh(mesh);
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
	mesh->grid = read_mesh(fd, 0, 0);
	mesh->size_x = array_size(mesh->grid[0]) * 10;
	mesh->size_y = arr_arr_size(mesh->grid) * 10;
	mesh->mlx = mlx_init();
	mesh->mlx_win = mlx_new_window(mesh->mlx, mesh->size_x, mesh->size_y, "FDF?");
	mlx_loop_hook(mesh->mlx, print_mesh, mesh);
	mlx_loop(mesh->mlx);
	close(fd);
}

