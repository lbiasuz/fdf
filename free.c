/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:47:06 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/08/27 23:42:03 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_point(t_point	*point)
{
	free(point);
	point = NULL;
}

void	free_line(void	*list)
{
	ft_lstiter(list, free);
}

void	free_mesh(t_mesh *mesh)
{
	ft_lstiter(mesh->grid, free_line);
	free(mesh->image_str);
	mlx_destroy_window(mesh->mlx, mesh->mlx_win);
	free(mesh->mlx);
	free(mesh);
	mesh = NULL;
}
