/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:45:04 by smago             #+#    #+#             */
/*   Updated: 2020/10/12 20:04:29 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_res(t_cub *cub, char *str)
{
	int x;
	int y;

	mlx_get_screen_size(cub->mlx.ptr, &x, &y);
	while (*str >= '0' && *str <= '9')
	{
		cub->win.x = cub->win.x * 10 + (*str - '0');
		str++;
		if (cub->win.x > x)
			cub->win.x = x;
	}
	str = ft_spaces(str);
	while (*str >= '0' && *str <= '9')
	{
		cub->win.y = cub->win.y * 10 + (*str - '0');
		str++;
		if (cub->win.y > y)
			cub->win.y = y;
	}
	return (str);
}

int			ft_resolution(t_cub *cub, char *str)
{
	if (cub->win.x != 0 && cub->win.y != 0)
		return (-4);
	str++;
	str = ft_spaces(str);
	str = ft_res(cub, str);
	str = ft_spaces(str);
	if (*str != '\0' || cub->win.x <= 0 || cub->win.y <= 0)
		return (-4);
	return (0);
}
