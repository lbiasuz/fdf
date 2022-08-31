/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:57:35 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/08/30 23:20:59 by lbiasuz          ###   ########.fr       */
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

t_list	*get_line_split(char *line, int x, int y)
{
	char	**split;
	t_list	*list;
	int		i;

	i = 0;
	split = ft_split(line, ' ');
	list = ft_lstnew(new_point(x, y, split[i]));
	while (split[i])
	{
		x += 10;
		y += 5;
		i++;
		ft_lstadd_back((void *) list, ft_lstnew(new_point(x, y, split[i])));
	}
	free_arr(split);
	return (list);
}

t_list	*read_mesh(int fd)
{
	t_list	*list;
	char	*line;
	int		y;
	int		x;

	x = 0;
	y = 0;
	line = get_next_line(fd);
	list = ft_lstnew(get_line_split(line, x, y));
	while (line)
	{
		free(line);
		x -= 5;
		y += 10;
		line = get_next_line(fd);
		ft_lstadd_back(&list, get_line_split(line, x, y));
	}
	return (list);
}

