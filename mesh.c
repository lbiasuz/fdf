#include "fdf.h"

t_mesh	*init_mesh(int fd)
{
	t_mesh	*mesh;

	mesh = malloc(sizeof(t_mesh));
	mesh->bpp = 32;
	mesh->endianes = 0;
	mesh->size_scale = 20;
	mesh->grid = read_mesh(fd, 0, 0, mesh->size_scale);
	mesh->arr_x = array_size(mesh->grid[0]);
	mesh->arr_y = arr_arr_size(mesh->grid);
	mesh->size_x = 1200; 
	mesh->size_y = 1000; 
	mesh->line_size = 1200;
	mesh->angle = -30 * 3.1415f / 180;
	mesh->mlx = mlx_init();
	mesh->mlx_win = mlx_new_window(
			mesh->mlx, mesh->size_x, mesh->size_y, "FDF?"
			);
	mesh->image = mlx_new_image(mesh->mlx, mesh->size_x, mesh->size_y);
	mesh->image_str = mlx_get_data_addr(
			mesh->image, &mesh->bpp, &mesh->line_size, &mesh->endianes
			);
	return (mesh);
}

void	iterate_mesh(t_mesh *mesh, void (*f)(t_point *, t_mesh *))
{
	int	iy;
	int	ix;	

	iy = 0;
	ix = 0;
	while (mesh->grid[iy])
	{
		while (mesh->grid[iy][ix])
		{
			f(mesh->grid[iy][ix], mesh);
			ix++;
		}
		ix = 0;
		iy++;
	}
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
