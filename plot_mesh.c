/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:23:39 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/08/30 23:03:11 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_point point, t_mesh *mesh)
{
	char *aux;
	
	if (
		(point.x < mesh->size_x && point.x >= 0) && 
		(point.y < mesh->size_y / 5 && point.y >= 0)
	)
	{
		aux = mesh->image_str + (((point.y * mesh->size_x) + point.x) * (mesh->bpp / 8));
		*(unsigned int*)aux = point.color;
	}
}

void	plot_line(t_point *beg, t_point *end, t_mesh *mesh)
{
	t_point	aux;
	int		d;

	aux = (t_point){.x = beg->x, .y = beg->y, .z = beg->z, .color = beg->color};
	d = (2 * (end->y - beg->y) - (end->x - beg->x));
	if ((end->y - beg->y) - (end->x - beg->x) <= 1)
	{
		while (aux.x < end->x)
		{
			put_pixel(aux, mesh);
			if (d > 0)
			{
				d += 2 * ((end->y - beg->y) - (end->x - beg->x));
				aux.y++;
			}
			else
				d += 2 * (end->y - beg->y);
			aux.x++;
		}
	}
	else
	{
		while (aux.y < end->y)
		{
			put_pixel(aux, mesh);
			if (d < 0)
			{
				d += 2 * ((end->x - beg->x) - (end->y - beg->y));
				aux.x++;
			}
			else
				d += 2 * (end->x - beg->x);
			aux.y++;
		}
	}
}

void	plot_mesh(t_mesh *mesh)
{
	t_point		***y_aux;
	t_point		**x_aux;
	int		i;
	int		j;
	
	j = 0;
	y_aux = mesh->grid;
	while(y_aux[0] && y_aux[j])
	{
		i = 0;
		x_aux = y_aux[j];
		while(x_aux[0] && x_aux[i + 1])
		{
			if (x_aux[i]->x < x_aux[i + 1]->x)
				plot_line(x_aux[i], x_aux[i + 1], mesh);
			else
				plot_line(x_aux[i + 1], x_aux[i], mesh);
			if (y_aux[j + 1] && y_aux[j + 1][i])
				plot_line(x_aux[i], y_aux[j + 1][i], mesh);
			i++;
		}
		if (y_aux[j + 1] && y_aux[j + 1][i])
			plot_line(x_aux[i], y_aux[j + 1][i], mesh);
		j++;
	}
}

