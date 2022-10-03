/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:30:00 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/10/02 17:49:24 by lbiasuz          ###   ########.fr       */
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

int	atoh(char *hex_string)
{
	char	*base;
	int		i;

	i = -1;
	base = "123456788ABCDEF";
	if (*hex_string == '0' && *(hex_string + 1) == 'x')
		hex_string += 2;
	while (ft_strchr(base, *hex_string))
	{
		i = (i * 10) + (ft_strchr(base, *hex_string) - base);
		hex_string++;
	}
	return (i);
}
