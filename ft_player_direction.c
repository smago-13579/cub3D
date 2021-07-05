/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_direction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:38:34 by smago             #+#    #+#             */
/*   Updated: 2020/10/12 20:04:12 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	p_dir3(t_map *map, int x, int y)
{
	while (map->maze[y])
	{
		x = 0;
		while (map->maze[y][x] != '\0')
		{
			if (map->maze[y][x] == ' ')
				map->maze[y][x] = '1';
			x++;
		}
		y++;
	}
}

static int	p_dir2(t_map *map, int x, int y, char ch)
{
	if (y != 0)
		if ((ft_strchr("02", ch)) && map->maze[y - 1][x] == ' ')
			return (-1);
	if (x != 0)
		if ((ft_strchr("02", ch)) && map->maze[y][x - 1] == ' ')
			return (-1);
	if (y != map->y)
		if ((ft_strchr("02", ch)) && map->maze[y + 1][x] == ' ')
			return (-1);
	if (x != map->x)
		if ((ft_strchr("02", ch)) && map->maze[y][x + 1] == ' ')
			return (-1);
	if (x == 0 || y == 0 || x == map->x || y == map->y)
		if ((ft_strchr(" 1", ch)) == NULL)
			return (-1);
	return (0);
}

static int	map_lines(t_map *map, int y, int i)
{
	char *str;

	while (map->maze[y])
	{
		str = &(map->maze)[y][0];
		str = ft_spaces(str);
		if (*str == '\0' && i == 0)
		{
			return (map_lines(map, y + 1, 1));
		}
		else if (*str != '\0' && i == 1)
			return (-1);
		y++;
	}
	return (0);
}

int			p_dir(t_map *map, int x, int y)
{
	while (map->maze[y])
	{
		x = 0;
		if (map_lines(map, y, 0) < 0)
			return (-1);
		while (map->maze[y][x] != '\0')
		{
			if (p_dir2(map, x, y, map->maze[y][x]) < 0)
			{
				return (-1);
			}
			x++;
		}
		y++;
	}
	p_dir3(map, 0, 0);
	return (0);
}
