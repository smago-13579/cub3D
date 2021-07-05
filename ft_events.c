/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:27:42 by smago             #+#    #+#             */
/*   Updated: 2020/10/02 16:17:29 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_rotation(t_cub *cub, int key)
{
	mlx_destroy_image(cub->mlx.ptr, cub->img.ptr);
	cub->img.ptr = mlx_new_image(cub->mlx.ptr, cub->win.x, cub->win.y);
	cub->img.addr = mlx_get_data_addr(cub->img.ptr, &cub->img.bits, \
										&cub->img.line, &cub->img.endian);
	if (key == LEFT)
		cub->player.a -= M_PI_4 / 10;
	else if (key == RIGHT)
		cub->player.a += M_PI_4 / 10;
	if (cub->player.a >= 2 * M_PI)
		cub->player.a -= 2 * M_PI;
	else if (cub->player.a <= -2 * M_PI)
		cub->player.a += 2 * M_PI;
	ray_pixel_put(cub, &cub->player, &cub->ray);
	mlx_put_image_to_window(cub->mlx.ptr, cub->win.ptr, cub->img.ptr, 0, 0);
}

int		ft_close(t_cub *cub)
{
	mlx_destroy_window(cub->mlx.ptr, cub->win.ptr);
	ft_errors(cub, 0);
	return (0);
}

int		ft_events(int key, t_cub *cub)
{
	if (key == ESC)
	{
		mlx_destroy_window(cub->mlx.ptr, cub->win.ptr);
		ft_errors(cub, 0);
	}
	else if (key == W || key == S || key == A || key == D)
	{
		mlx_destroy_image(cub->mlx.ptr, cub->img.ptr);
		player_position(cub, key);
		cub->img.ptr = mlx_new_image(cub->mlx.ptr, cub->win.x, cub->win.y);
		cub->img.addr = mlx_get_data_addr(cub->img.ptr, &cub->img.bits, \
											&cub->img.line, &cub->img.endian);
		ray_pixel_put(cub, &cub->player, &cub->ray);
		mlx_put_image_to_window(cub->mlx.ptr, cub->win.ptr, cub->img.ptr, 0, 0);
	}
	else if (key == LEFT || key == RIGHT)
		player_rotation(cub, key);
	return (0);
}
