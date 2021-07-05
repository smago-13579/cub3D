/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:03:26 by smago             #+#    #+#             */
/*   Updated: 2020/09/26 18:56:39 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_karta(t_parse *parse)
{
	int i;

	i = 0;
	while (parse->karta[i])
	{
		free(parse->karta[i]);
		parse->karta[i] = NULL;
		i++;
	}
	free(parse->karta);
	parse->karta = NULL;
}

static int	check_all(t_cub *cub)
{
	int i;

	i = 0;
	if (cub->tex.i[0] == 0 || cub->tex.i[1] == 0 || \
		cub->win.x == 0 || cub->win.y == 0)
	{
		return (-4);
	}
	while (i < 5)
	{
		if (cub->tex_ns.adr[i] == NULL)
		{
			return (-4);
		}
		i++;
	}
	return (0);
}

int			ft_create_map(t_cub *cub, int i)
{
	int j;
	int x;

	j = 0;
	if (check_all(cub) < 0)
		return (-4);
	if (!(cub->map.maze = ft_calloc((cub->parse.y - i + 1), sizeof(char *))))
		return (-2);
	while ((cub->parse.karta)[i])
	{
		x = -1;
		if (!((cub->map.maze)[j] = ft_calloc((cub->parse.x + 1), sizeof(char))))
			return (-2);
		while ((cub->parse.karta)[i][++x])
			(cub->map.maze)[j][x] = (cub->parse.karta)[i][x];
		while (x < cub->parse.x)
			cub->map.maze[j][x++] = ' ';
		i++;
		j++;
	}
	cub->map.x = cub->parse.x;
	cub->map.y = j - 1;
	free_karta(&cub->parse);
	return (0);
}
