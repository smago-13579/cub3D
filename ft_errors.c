/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:08:58 by smago             #+#    #+#             */
/*   Updated: 2020/10/08 00:01:35 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_clear_cub2(t_cub *cub)
{
	if (cub->depth != NULL)
		free(cub->depth);
	if (cub->spr != NULL)
		free(cub->spr);
}

static void	ft_clear_cub(t_cub *cub)
{
	int i;

	i = -1;
	if (cub->parse.karta != NULL)
	{
		while (cub->parse.karta[++i] != NULL)
		{
			free(cub->parse.karta[i]);
			cub->parse.karta[i] = NULL;
		}
		free(cub->parse.karta);
		cub->parse.karta = NULL;
	}
	i = -1;
	if (cub->map.maze != NULL)
	{
		while (cub->map.maze[++i] != NULL)
		{
			free(cub->map.maze[i]);
			cub->map.maze[i] = NULL;
		}
		free(cub->map.maze);
		cub->map.maze = NULL;
	}
}

int			ft_errors(t_cub *cub, int i)
{
	ft_clear_cub(cub);
	ft_clear_cub2(cub);
	if (i < 0)
		write(1, "Error\n", 6);
	(i == -1) ? write(1, "Can't read file\n", 16) : 0;
	(i == -2) ? write(1, "Can't allocate memory\n", 22) : 0;
	(i == -3) ? write(1, "Can't create image\n", 19) : 0;
	(i == -4) ? write(1, "Invalid map\n", 12) : 0;
	(i == -5) ? write(1, "Invalid map name\n", 17) : 0;
	(i == -6) ? write(1, "Invalid number of arguments\n", 28) : 0;
	(i == -7) ? write(1, "Invalid argument name\n", 22) : 0;
	(i == -8) ? write(1, "Wrong texture format\n", 21) : 0;
	(i == -9) ? write(1, "Can't create screenshot\n", 19) : 0;
	exit(0);
}
