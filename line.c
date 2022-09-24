#include "fdf.h"

void	plot_line(t_point *beg, t_point *end, t_mesh *mesh)
{
	if ((end->y - beg->y) <= (end->x - beg->x))
	{
		if (beg->y <= end->y)
			plot_line_x(beg, end, mesh);
		else
			plot_line_nx(beg, end, mesh);
	}
	else
	{
		if (beg->x <= end->x)
			plot_line_y(beg, end, mesh);
		else
			plot_line_ny(beg, end, mesh);
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
	d = (2 * (eyz - byz) - (end->x - beg->x));
	while (aux.x <= end->x)
	{
		put_pixel(aux, mesh);
		if (d <= 0)
		{
			d += 2 * ((end->x - beg->x) - (eyz - byz));
			aux.y--;
		}
		else
			d += 2 * (eyz - byz);
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
	d = (2 * (eyz - byz) - (end->x - beg->x));
	while (aux.x <= end->x)
	{
		put_pixel(aux, mesh);
		if (d > 0)
		{
			d += 2 * ((eyz - byz) - (end->x - beg->x));
			aux.y++;
		}
		else
			d += 2 * (eyz - byz);
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
	d = (2 * (end->x - beg->x) - (eyz - byz));
	while (aux.y <= eyz)
	{
		put_pixel(aux, mesh);
		if (d < 0)
		{
			d += 2 * ((eyz - byz) - (end->x - beg->x));
			aux.x -= 2;
		}
		else
			d += 2 * (end->x - beg->x);
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
	d = (2 * (eyz - byz) - (end->x - beg->x));
	while (aux.y <= end->y)
	{
		put_pixel(aux, mesh);
		if (d > 0)
		{
			d += 2 * ((end->x - beg->x) - (eyz - byz));
			aux.x++;
		}
		else
			d += 2 * (end->x - beg->x);
		aux.y++;
	}
}
