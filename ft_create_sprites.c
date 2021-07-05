/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:29:56 by smago             #+#    #+#             */
/*   Updated: 2020/10/02 16:38:54 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_create_sprites(t_map *map, t_cub *cub, int i)
{
	int x;
	int y;

	y = 0;
	if (!(cub->spr = ft_calloc(cub->tex.spr_i, sizeof(t_spr))))
		return (-1);
	while (map->maze[y])
	{
		x = 0;
		while (map->maze[y][x] != '\0')
		{
			if (map->maze[y][x] == '2')
			{
				cub->spr[i].x = (double)x + 0.5;
				cub->spr[i].y = (double)y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
	return (0);
}
