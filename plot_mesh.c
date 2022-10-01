/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:23:39 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/10/01 13:07:15 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_point point, t_mesh *mesh)
{
	char	*aux;

	if (
		(point.x < mesh->size_x && point.x >= 0)
		&& (point.y < mesh->size_y && point.y >= 0)
	)
	{
		aux = mesh->image_str + (
				((point.y) * mesh->line_size) + point.x * (mesh->bpp / 8)
				);
		*(unsigned int *) aux = point.color + (1000 * point.z);
	}
}

void	plot_mesh(t_mesh *mesh)
{
	t_point		***y_aux;
	t_point		**x_aux;
	int			i;
	int			j;

	j = 0;
	y_aux = mesh->grid;
	while (y_aux[0] && y_aux[j])
	{
		i = 0;
		x_aux = y_aux[j];
		while (x_aux[0] && x_aux[i + 1])
		{
			plot_line(x_aux[i], x_aux[i + 1], mesh);
			if (y_aux[j + 1] && y_aux[j + 1][i])
				plot_line(x_aux[i], y_aux[j + 1][i], mesh);
			i++;
		}
		if (y_aux[j + 1] && y_aux[j + 1][i])
			plot_line(x_aux[i], y_aux[j + 1][i], mesh);
		j++;
	}
}
