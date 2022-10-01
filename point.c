/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:48:36 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/10/01 17:08:43 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void move_point(t_point *point, t_mesh *mesh)
{
  point->y = point->y + mesh->y_offset;
  point->x = point->x + mesh->x_offset;
}

void	center_point(t_point *point, t_mesh *mesh)
{
	point->y += mesh->size_y / 2 - (mesh->arr_y * mesh->size_scale / 2);
	point->x += mesh->size_x / 2 - (mesh->arr_x * mesh->size_scale / 2);
}

void	rotate_point(t_point *point, t_mesh *mesh)
{
	float	s;
	float	c;
	t_point	aux;

	s = sin(mesh->angle);
	c = cos(mesh->angle);
	point->x -= mesh->size_x / 2;
	point->y -= mesh->size_y / 2;
	aux.x = point->x * c + point->y * s;
	aux.y = -point->x * s + point->y * c;
	point->x = aux.x + mesh->size_x / 2;
	point->y = aux.y + mesh->size_y / 2;
}

void	refresh_point(t_point *point, t_mesh *mesh)
{
	point->y = point->py * mesh->size_scale;
	point->x = point->px * mesh->size_scale;
}
