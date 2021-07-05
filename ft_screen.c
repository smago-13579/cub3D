/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 19:35:57 by smago             #+#    #+#             */
/*   Updated: 2020/10/13 21:12:07 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	player_pos(t_player *player, int x, int y, char *str)
{
	if (player->x != 0 && player->y != 0)
		return (-1);
	if (*str == 'N' || *str == 'S')
		player->a = (*str == 'N') ? (3 * M_PI_2) : M_PI_2;
	else if (*str == 'W' || *str == 'E')
		player->a = (*str == 'W') ? M_PI : 0;
	*str = '0';
	player->x = (double)x + 0.5;
	player->y = (double)y + 0.5;
	return (0);
}

static int	check_map2(char *str, t_map *map, t_cub *cub, int y)
{
	int x;

	x = 0;
	while (*str != '\0')
	{
		while (*str == '0' || *str == '1' || *str == '2' || *str == 'N' || \
				*str == 'S' || *str == 'W' || *str == 'E' || *str == ' ')
			str++;
		if (*str != '\0')
			return (-4);
	}
	while (map->maze[y][x] != '\0')
	{
		if (map->maze[y][x] == 'N' || map->maze[y][x] == 'S' ||\
			map->maze[y][x] == 'W' || map->maze[y][x] == 'E')
		{
			if ((player_pos(&cub->player, x, y, &(map->maze)[y][x])) < 0)
				return (-4);
		}
		else if (map->maze[y][x] == '2')
			(cub->tex).spr_i++;
		x++;
	}
	return (0);
}

static int	check_map(t_map *map, t_cub *cub)
{
	int y;

	y = 0;
	while (map->maze[y] != NULL)
	{
		if ((check_map2(&(map->maze)[y][0], map, cub, y)) < 0)
			return (-1);
		y++;
	}
	if (cub->player.x == 0 && cub->player.y == 0)
		return (-1);
	if ((ft_create_sprites(map, cub, 0)) < 0)
		return (-1);
	return (0);
}

int			ft_screen(t_cub *cub, int i)
{
	if ((check_map(&cub->map, cub)) < 0)
		return (ft_errors(cub, -4));
	if ((p_dir(&cub->map, 0, 0)) < 0)
		return (ft_errors(cub, -4));
	if (i == 1)
		cub->win.ptr = mlx_new_window(cub->mlx.ptr, cub->win.x, \
						cub->win.y, "smago_cub3d");
	cub->img.ptr = mlx_new_image(cub->mlx.ptr, cub->win.x, cub->win.y);
	cub->img.addr = mlx_get_data_addr(cub->img.ptr, &cub->img.bits, \
					&cub->img.line, &cub->img.endian);
	ray_pixel_put(cub, &cub->player, &cub->ray);
	return (0);
}
