/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:53:35 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/10/03 07:53:41 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_line(t_point *beg, t_point *end, t_mesh *mesh)
{
	if (ft_abs((end->y - end->z) - (beg->y - beg->z)) < ft_abs(end->x - beg->x))
	{
		if (beg->x <= end->x && (beg->y - beg->z) <= (end->y - end->z))
			plot_line_x(beg, end, mesh);
		else if (beg->x <= end->x && (beg->y - beg->z) > (end->y - end->z))
			plot_line_nx(beg, end, mesh);
		else if (beg->x > end->x && (beg->y - beg->z) <= (end->y - end->z))
			plot_line_nx(end, beg, mesh);
		else
			plot_line_x(end, beg, mesh);
	}
	else
	{
		if (beg->x < end->x && ((beg->y - beg->z) <= (end->y - end->z)))
			plot_line_y(beg, end, mesh);
		else if (beg->x < end->x && ((beg->y - beg->z) > (end->y - end->z)))
			plot_line_ny(end, beg, mesh);
		else if (beg->x >= end->x && ((beg->y - beg->z) <= (end->y - end->z)))
			plot_line_ny(beg, end, mesh);
		else
			plot_line_y(end, beg, mesh);
	}
}

void	plot_line_nx(t_point *beg, t_point *end, t_mesh *mesh)
{
	t_point	aux;
	int		d;
	int		byz;
	int		eyz;

	byz = beg->y - beg->z;
	eyz = end->y - end->z;
	aux = (t_point){.x = beg->x, .y = byz, .z = beg->z, .color = beg->color};
	d = (2 * ft_abs(eyz - byz) - ft_abs(end->x - beg->x));
	while (aux.x <= end->x)
	{
		put_pixel(aux, mesh);
		if (d >= 0)
		{
			d += 2 * (ft_abs(eyz - byz) - ft_abs(end->x - beg->x));
			aux.y--;
		}
		else
			d += 2 * ft_abs(eyz - byz);
		aux.x++;
	}
}

void	plot_line_x(t_point *beg, t_point *end, t_mesh *mesh)
{
	t_point	aux;
	int		d;
	int		byz;
	int		eyz;

	byz = beg->y - beg->z;
	eyz = end->y - end->z;
	aux = (t_point){.x = beg->x, .z = beg->z, .y = byz, .color = beg->color};
	d = (2 * ft_abs(eyz - byz) - ft_abs(end->x - beg->x));
	while (aux.x <= end->x)
	{
		put_pixel(aux, mesh);
		if (d >= 0)
		{
			d += 2 * (ft_abs(eyz - byz) - ft_abs(end->x - beg->x));
			aux.y++;
		}
		else
			d += 2 * ft_abs(eyz - byz);
		aux.x++;
	}
}

void	plot_line_ny(t_point *beg, t_point *end, t_mesh *mesh)
{
	t_point	aux;
	int		d;
	int		byz;
	int		eyz;

	byz = beg->y - beg->z;
	eyz = end->y - end->z;
	aux = (t_point){.x = beg->x, .y = byz, .z = beg->z, .color = beg->color};
	d = (2 * ft_abs(eyz - byz) - ft_abs(end->x - beg->x));
	while (aux.y <= eyz)
	{
		put_pixel(aux, mesh);
		if (d >= 0)
		{
			d += 2 * (ft_abs(end->x - beg->x) - ft_abs(eyz - byz));
			aux.x--;
		}
		else
			d += 2 * ft_abs(end->x - beg->x);
		aux.y++;
	}
}

void	plot_line_y(t_point *beg, t_point *end, t_mesh *mesh)
{
	t_point	aux;
	int		d;
	int		byz;
	int		eyz;

	byz = beg->y - beg->z;
	eyz = end->y - end->z;
	aux = (t_point){.x = beg->x, .y = byz, .z = beg->z, .color = beg->color};
	d = (2 * ft_abs(beg->x - end->x) - ft_abs(eyz - byz));
	while (aux.y <= eyz)
	{
		put_pixel(aux, mesh);
		if (d >= 0)
		{
			d += 2 * (ft_abs(beg->x - end->x) - ft_abs(eyz - byz));
			aux.x++;
		}
		else
			d += 2 * ft_abs(beg->x - end->x);
		aux.y++;
	}
}
