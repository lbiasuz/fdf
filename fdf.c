/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:37:37 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/10/01 13:02:10 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_mesh(void *aux)
{
	t_mesh		*mesh;

	mesh = (t_mesh *) aux;
	if (mesh->mlx && mesh->mlx_win)
	{
	//	mlx_clear_window(mesh->mlx, mesh->mlx_win);
		plot_mesh(mesh);
		mlx_put_image_to_window(mesh->mlx, mesh->mlx_win, mesh->image, 0, 0);
	}
	return (0);
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
	mesh = init_mesh(fd);
	iterate_mesh(mesh, center_point);
	iterate_mesh(mesh, rotate_point);
	mlx_key_hook(mesh->mlx_win, handle_scale, mesh);
	//mlx_key_hook(mesh->mlx_win, handle_close, mesh);
	mlx_loop_hook(mesh->mlx, print_mesh, mesh);
	mlx_loop(mesh->mlx);
	close(fd);
}
