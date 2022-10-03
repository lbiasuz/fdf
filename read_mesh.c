/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:57:35 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/10/02 18:09:38 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**get_line_split(char *line, int x, int y, int size_scale)
{
	char		**split;
	t_point		**vec;
	int			i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	vec = ft_calloc(i, sizeof(t_point));
	if (!vec)
		return (NULL);
	vec[i] = NULL;
	x += size_scale * i;
	while (--i >= 0)
	{
		vec[i] = new_point(x, y, split[i], size_scale);
		x -= size_scale;
	}
	free_arr(split);
	return (vec);
}

t_point	***append_to_end(t_point ***list, t_point **line)
{
	t_point	***res;
	int		i;

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
	t_point	***list;
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
