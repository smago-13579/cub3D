/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:44:55 by smago             #+#    #+#             */
/*   Updated: 2020/10/12 13:32:06 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_pixels(t_img1 *img, int i, int j, int color)
{
	char *dst;

	dst = img->addr + j * img->line + i * (img->bits / 8);
	*(unsigned int*)dst = color;
}

static int	draw_textures(t_cub *cub, double offset, int j)
{
	char	*dst;
	int		color;
	int		side;

	side = cub->tex.index;
	j = (j - cub->win.y / 2 + cub->ray.height / 2);
	dst = cub->tex_ns.adr[side] + \
	((int)(j * (cub->tex_ns.height[side] / cub->ray.height)) * \
	cub->tex_ns.line[side]) + ((int)(offset * \
	(double)cub->tex_ns.width[side])) * (cub->tex_ns.bits[side] / 8);
	color = *(unsigned int*)dst;
	return (color);
}

void		draw_line(t_cub *cub, int start, double offset)
{
	int i;
	int j;
	int color;

	i = cub->img.x;
	j = start - (int)(cub->ray.height / 2);
	while (j <= (start + (int)(cub->ray.height / 2)))
	{
		if (j >= 0 && j < cub->win.y)
		{
			color = draw_textures(cub, offset, j);
			draw_pixels(&cub->img, i, j, color);
		}
		j++;
	}
}
