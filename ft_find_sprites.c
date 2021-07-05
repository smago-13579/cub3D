/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 21:45:59 by smago             #+#    #+#             */
/*   Updated: 2020/10/15 21:52:14 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	draw_textures(t_cub *cub, int x, int y)
{
	char	*dst;
	int		color;
	int		side;

	side = cub->tex.index;
	y = y - (cub->win.y / 2) + (int)(cub->ray.height / 2);
	x = x - (cub->win.x / 2) + (int)cub->tex.offset;
	dst = cub->tex_ns.adr[side] + ((int)(y * \
	(cub->tex_ns.height[side] / cub->ray.height)) * \
	cub->tex_ns.line[side]) + ((int)(x * (double)cub->tex_ns.width[side] / \
	cub->ray.height)) * (cub->tex_ns.bits[side] / 8);
	color = *(unsigned int*)dst;
	return (color);
}

static void	draw_sprite(t_cub *cub, int x, int y, int i)
{
	int color;

	if (cub->depth[x] > cub->spr[i].d && cub->spr[i].d > 0.3)
	{
		while (y <= (cub->win.y / 2) + (int)(cub->ray.height / 2))
		{
			if (y >= 0 && y < cub->win.y)
			{
				color = draw_textures(cub, x, y);
				if (color > 2000000)
					draw_pixels(&cub->img, x, y, color);
			}
			y++;
		}
	}
}

static void	display_spr(t_cub *cub, t_spr *spr, t_player *player, int i)
{
	double	diff;
	int		wide;
	int		x;
	int		y;

	while (i < cub->tex.spr_i)
	{
		diff = player->a - spr[i].a;
		cub->ray.height = cub->win.y / spr[i].d;
		if (cub->win.x < cub->win.y)
			cub->ray.height = cub->win.x / spr[i].d;
		y = (cub->win.y / 2) - (int)(cub->ray.height / 2);
		cub->tex.offset = diff * (double)cub->win.x / player->fov \
			+ cub->ray.height / 2;
		x = (cub->win.x / 2) - (int)cub->tex.offset;
		wide = x + (int)cub->ray.height;
		while (x <= wide && wide >= 0)
		{
			if (x >= 0 && x < cub->win.x)
				draw_sprite(cub, x, y, i);
			x++;
		}
		i++;
	}
}

static void	sort_sprites(t_cub *cub, t_spr *spr, int i)
{
	t_spr tmp;

	while (i < cub->tex.spr_i)
	{
		while (i - 1 >= 0 && spr[i].d > spr[i - 1].d)
		{
			tmp.x = spr[i - 1].x;
			tmp.y = spr[i - 1].y;
			tmp.a = spr[i - 1].a;
			tmp.d = spr[i - 1].d;
			spr[i - 1].x = spr[i].x;
			spr[i - 1].y = spr[i].y;
			spr[i - 1].a = spr[i].a;
			spr[i - 1].d = spr[i].d;
			spr[i].x = tmp.x;
			spr[i].y = tmp.y;
			spr[i].d = tmp.d;
			spr[i].a = tmp.a;
			i--;
		}
		i++;
	}
}

void		ft_find_sprites(t_cub *cub, t_player *player, t_spr *spr, int i)
{
	cub->tex.index = 4;
	while (i < cub->tex.spr_i)
	{
		spr[i].d = sqrt(pow(spr[i].x - player->x, 2) + \
		pow(spr[i].y - player->y, 2));
		spr[i].a = atan2(spr[i].y - player->y, spr[i].x - player->x);
		while (spr[i].a - player->a > M_PI)
			spr[i].a -= 2 * M_PI;
		while (spr[i].a - player->a < -M_PI)
			spr[i].a += 2 * M_PI;
		i++;
	}
	sort_sprites(cub, spr, 1);
	display_spr(cub, spr, player, 0);
}
