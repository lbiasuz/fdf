/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:32:20 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/08/30 22:26:33 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mesh	*start_window(t_mesh *mesh)
{
	void	*mlx_win;
	
	mesh->mlx = mlx_init();
	mesh->mlx_win = mlx_new_window(
		mesh->mlx, mesh->size_x * 10, mesh->size_y * 10, "FDF");
	return (mesh);
}

