/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:30:00 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/10/01 15:23:34 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	array_size(t_point **list)
{
	int	i;

	i = 0;
	while (list && list[i])
		i++;
	return (i);
}

int	arr_arr_size(t_point ***list)
{
	int	i;

	i = 0;
	while (list && list[i])
		i++;
	return (i);
}
