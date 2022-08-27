/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:51:41 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/08/27 16:46:35 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_fdf(char *file_name)
{
	int	fd;

	fd = open(file_name);
	if (!fd)
		ft_printf("FILE ERROR: path %s not found", file_name);
	return (fd);
}
