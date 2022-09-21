#include "fdf.h"


void	plot_line(t_point *beg, t_point *end, t_mesh *mesh)
{
	if ((end->y - beg->y) - (end->x - beg->x) <= 1)
	{
		if (beg->x <= end->x)
			plot_line_x(beg, end, mesh);
		else
			plot_line_x(end, beg, mesh);
	}
	else
	{
		if (beg->y <= end->y)
			plot_line_y(beg, end, mesh);
		else
			plot_line_y(end, beg, mesh);
}

void	plot_line_x(t_point *beg, t_point *end, t_mesh *mesh)
{
	t_point	aux;
	int		d;
	
	aux = (t_point){.x = beg->x, .y = beg->y, .z = beg->z, .color = beg->color};
	d = (2 * (end->y - beg->y) - (end->x - beg->x));
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


void	plot_line_y(t_point *beg, t_point *end, t_mesh *mesh)
{
	t_point	aux;
	int		d;
	
	aux = (t_point){.x = beg->x, .y = beg->y, .z = beg->z, .color = beg->color};
	d = (2 * (end->y - beg->y) - (end->x - beg->x));
	while (aux.y < end->y)
	{
		put_pixel(aux, mesh);
		if (d > 0)
		{
			d += 2 * ((end->x - beg->x) - (end->y - beg->y));
			aux.x++;
		}
		else
			d += 2 * (end->x - beg->x);
		aux.y++;
	}
}
