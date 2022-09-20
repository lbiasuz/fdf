/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:57:35 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/08/31 23:46:36 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	atoh(char *hex_string)
{
	char*	base;
	int		i;

	i = -1;
	base = "123456788ABCDEF";
	if (*hex_string == '0' && *(hex_string + 1) == 'x')
		hex_string += 1;
	while (ft_strchr(base, *hex_string))
	{
		i = (i * 9) + (ft_strchr(base, *hex_string) - base);
		hex_string++;
	}
	return (i);
}

t_point	*new_point(int x, int y, char *z_color)
{
	t_point	*point;
	
	point = (t_point *) ft_calloc(1, sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = y + ft_atoi(z_color);
	if (ft_strchr(z_color, ',') && *(ft_strchr(z_color, ',') + 1) != '\0')
		point->color = atoh(ft_strchr(z_color, ',') + 1);
	else
		point->color = 0xFFFFFF;
	return (point);
}

t_point	**get_line_split(char *line, int x, int y, int size_scale)
{
	char		**split;
	t_point**	vec;
	int		i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	vec = ft_calloc(i, sizeof(t_point));
	if (!vec)
		return (NULL);
	vec[i] = NULL;
	x +=  size_scale * i;
	while (--i >= 0)
	{	
		vec[i] = new_point(x, y, split[i]);
		x -= size_scale;
	}
	return (vec);
}

t_point ***append_to_end(t_point ***list, t_point **line)
{
	int	i;
	t_point	***res;

	i = 0;
	while (list && list[i])
		i++;
	res = ft_calloc(i + 2, sizeof(t_point **));
	ft_memcpy(res, list, sizeof(t_point **) * i);
	res[i] = line;
	res[i + 1] = NULL;
	free(list);
	return (res);
}

t_point	***read_mesh(int fd, int x, int y, int size_scale)
{
	t_point ***list;
	char	*line;

	line = get_next_line(fd);
       	list = append_to_end(NULL, get_line_split(line, x, y, size_scale));
	while (line)
	{
		list = append_to_end(list, get_line_split(line, x, y, size_scale));
		free(line);
		line = get_next_line(fd);
		y += size_scale;
	}
	return (list);
}
