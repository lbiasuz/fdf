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
	int i;
	int j;

	i = 0;
	j = 0;
	while (mesh->grid[i])
	{
		while(mesh->grid[i][j++])
			free_point(mesh->grid[i][j]);
		free(mesh->grid[i]);
		i++;
	}
	free(mesh->grid);
}
