/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:37:37 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/08/30 23:57:44 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	main(int argc, char **argv)
{
	int		fd;
	t_mesh	*mesh;

	fd = open_fdf(argv[1]);
	mesh = malloc(sizeof(t_mesh));
	mesh->grid = read_mesh(fd);
	mesh->mlx = mlx_init();
	mesh->size_y = ft_lstsize(mesh->grid) * 10;
	mesh->size_x = ft_lstsize(mesh->grid->content) * 10;
	// TODO
}
