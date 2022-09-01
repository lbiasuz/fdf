/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:23:39 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/08/30 23:03:11lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_point point, t_mesh *mesh)
{
	int	*i;
	
	i = (int *) mesh->image_str + 4 * (point.x + point.y * mesh->size_y);
	*i = point.color;
}

void	plot_line(t_point *beg, t_point *end, t_mesh *mesh)
{
	int		d;
	t_point	aux;

	aux = (t_point){.x = beg->x, .y = beg->y, .z = beg->z, .color = beg->color};
	d = (2 * (end->y - beg->y) - (end->x - beg->x));
	while (aux.x < end->x)
	{
		put_pixel(aux, mesh);
		if (d > 0)
			d += 2 * ((end->y - beg->y) - (end->x - beg->x));
		else
			d += 2 * (end->y - beg->y);
		aux.y += d > 0;
		aux.x++;
	}
}

void	plot_mesh(t_mesh *mesh)
{
	t_list	*y_aux;
	t_list	*x_aux;
	
	y_aux = mesh->grid;
	while(y_aux->next)
	{
		x_aux = y_aux->content;
		while(x_aux->next)
		{
			plot_line(x_aux->content, x_aux->next->content, mesh);
			x_aux = x_aux->next;
		}
		y_aux = mesh->grid->next;
	}
}
