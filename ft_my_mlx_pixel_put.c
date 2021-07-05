/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_mlx_pixel_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 19:07:29 by smago             #+#    #+#             */
/*   Updated: 2020/10/09 13:56:45 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	find_offset2(double z)
{
	if (z < 0)
		z += 2 * M_PI;
	if (z <= M_PI / 4 || z > 7 * M_PI / 4)
		return (3);
	else if (z > M_PI * 4 && z <= 3 * M_PI / 4)
		return (1);
	else if (z > 3 * M_PI / 4 && z <= 5 * M_PI / 4)
		return (2);
	else
		return (0);
}

static void	find_offset(t_cub *cub, t_crd *crd, double z)
{
	int x;
	int y;

	x = (int)crd->i - (int)(crd->i - (RL * cos(z)));
	y = (int)crd->j - (int)(crd->j - (RL * sin(z)));
	if (x != 0 && y == 0)
	{
		cub->tex.offset = crd->j - floor(crd->j);
		cub->tex.index = (cub->player.x < crd->i) ? 2 : 3;
	}
	else if (y != 0 && x == 0)
	{
		cub->tex.offset = crd->i - floor(crd->i);
		cub->tex.index = (cub->player.y < crd->j) ? 0 : 1;
	}
	else
	{
		cub->tex.offset = 0;
		if (cub->img.x == 0)
			cub->tex.index = find_offset2(z);
	}
	cub->ray.height = (cub->win.y / \
			(cub->ray.len * fabs(cos(z - cub->player.a))));
}

static void	rays_dir(t_cub *cub, t_player *player, t_ray *ray, double z)
{
	t_crd	crd;
	int		x;
	int		y;

	crd.i = player->x;
	crd.j = player->y;
	x = (int)crd.i;
	y = (int)crd.j;
	ray->len = RL;
	while (cub->map.maze[y][x] != '1')
	{
		crd.i = player->x + ray->len * cos(z);
		crd.j = player->y + ray->len * sin(z);
		ray->len += RL;
		x = (int)crd.i;
		y = (int)crd.j;
	}
	ray->len -= RL;
	cub->depth[cub->img.x] = ray->len;
	find_offset(cub, &crd, z);
}

static void	draw_ceil_floor(t_img1 *img, t_tex *tex, t_win *win)
{
	int x;
	int y;

	y = -1;
	while (++y < win->y)
	{
		x = -1;
		while (++x < win->x)
		{
			if (y < (win->y / 2))
				draw_pixels(img, x, y, tex->ceil);
			else
				draw_pixels(img, x, y, tex->floor);
		}
	}
}

void		ray_pixel_put(t_cub *cub, t_player *player, t_ray *ray)
{
	double z;

	cub->img.x = 0;
	draw_ceil_floor(&cub->img, &cub->tex, &cub->win);
	z = player->a - (player->fov / 2);
	while (z <= player->a + (player->fov / 2))
	{
		rays_dir(cub, player, ray, z);
		draw_line(cub, (cub->win.y / 2), cub->tex.offset);
		z += player->fov / cub->win.x;
		cub->img.x += 1;
	}
	ft_find_sprites(cub, player, cub->spr, 0);
}
