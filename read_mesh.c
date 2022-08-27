/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbiasuz <lbiasuz@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:57:35 by lbiasuz           #+#    #+#             */
/*   Updated: 2022/08/27 16:45:36 by lbiasuz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_list	*get_line_split(char *line, int x, int y)
{
	char	**split;
	t_list	*list;
	t_point	*point;
	int		i;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
	{
		point = (t_point *) ft_calloc(sizeof(t_point));
		point->x = x;
		point->y = y;
		point->z = y + ft_atoi(split[i]);
		if (ft_strchr(pair, ',') && ft_strchr(pair, ',') + 1 != NULL)
			point->color = atoh(ft_strchr(pair, ',') + 1);
		ft_lstadd_back(point);
		x += 10;
		y += 5;
		i++;
	}
	return (list);
}

int	atoh(char *hex_string)
{
	char	base[16];
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (*hex_string == '0' && *(hex_string + 1) == 'x')
		hex_string += 2;
	while (ft_strchr(base, *hex_string))
	{
		i = (i * 10) + (ft_strchr(base, *hex_string) - base);
		hex_string++;
	}
	return (i);
}

char	*square_check(t_list *list)
{
	int	l_size;

	l_size = array_size(list);
	while (list->next)
	{
		if (array_size(list) != l_size)
		{
			ft_printf("File content is not square like grid representation");
			return (0);
		}
		list = list->next;
	}
	return (1);
}
