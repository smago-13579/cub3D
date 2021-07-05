/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:18:50 by smago             #+#    #+#             */
/*   Updated: 2020/10/14 22:58:06 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_position_w(t_cub *cub)
{
	int x;
	int y;

	x = (cub->player.x + STEP * cos(cub->player.a));
	y = (cub->player.y + STEP * sin(cub->player.a));
	if (cub->map.maze[y][x] == '0' || cub->map.maze[y][x] == '2')
	{
		cub->player.x += STEP * cos(cub->player.a);
		cub->player.y += STEP * sin(cub->player.a);
	}
}

static void	player_position_s(t_cub *cub)
{
	int x;
	int y;

	x = (cub->player.x - STEP * cos(cub->player.a));
	y = (cub->player.y - STEP * sin(cub->player.a));
	if (cub->map.maze[y][x] == '0' || cub->map.maze[y][x] == '2')
	{
		cub->player.x -= STEP * cos(cub->player.a);
		cub->player.y -= STEP * sin(cub->player.a);
	}
}

static void	player_position_a(t_cub *cub)
{
	int x;
	int y;

	x = (cub->player.x + STEP * sin(cub->player.a));
	y = (cub->player.y - STEP * cos(cub->player.a));
	if (cub->map.maze[y][x] == '0' || cub->map.maze[y][x] == '2')
	{
		cub->player.x += STEP * sin(cub->player.a);
		cub->player.y -= STEP * cos(cub->player.a);
	}
}

static void	player_position_d(t_cub *cub)
{
	int x;
	int y;

	x = (cub->player.x - STEP * sin(cub->player.a));
	y = (cub->player.y + STEP * cos(cub->player.a));
	if (cub->map.maze[y][x] == '0' || cub->map.maze[y][x] == '2')
	{
		cub->player.x -= STEP * sin(cub->player.a);
		cub->player.y += STEP * cos(cub->player.a);
	}
}

void		player_position(t_cub *cub, int key)
{
	if (key == W)
		player_position_w(cub);
	else if (key == S)
		player_position_s(cub);
	else if (key == A)
		player_position_a(cub);
	else if (key == D)
		player_position_d(cub);
}
