/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:37:37 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/08/31 22:50:21 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	mesh = (t_mesh *) malloc(sizeof(t_mesh));
	mesh->grid = read_mesh(fd);
	mesh->mlx = mlx_init();
	mesh->size_y = ft_lstsize(mesh->grid) * 10;
	mesh->size_x = ft_lstsize(mesh->grid->content) * 10;
	mesh->image_str = mlx_new_image(mesh->mlx, mesh->size_x, mesh-> size_y);
	plot_mesh(mesh);
	mlx_put_image_to_window(mesh->mlx, mesh->mlx_win, mesh->image_str, 0, 0);
	mlx_loop(mesh->mlx);
	close(fd);
}
