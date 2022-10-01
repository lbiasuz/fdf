/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:51:41 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/10/01 11:47:39 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_fdf(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		ft_printf("FILE ERROR: path %s not found", file_name);
	return (fd);
}
