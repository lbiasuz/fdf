/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:23:39 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/08/29 23:47:40 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_mesh(t_mesh *mesh)
{
	ft_lstiter(mesh, );
}

void	plot_line(t_point *beg, t_point *end, t_mesh * mesh)
{
	int		x;
	int		y;
	int		d;

	x = beg->x;
	y = beg->y;
	d = (2 * (end->y - beg->y) - (end->x - beg->x));
	while (x < end->x)
	{
		put_pixel(x, y, mesh);
		if (d > 0)
			d += 2 * ((end->y - beg->y) - (end->x - beg->x));
		else
			d += 2 * (end->y - beg->y);
		y += d > 0;
		x++;
	}
}
