/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 18:11:25 by smago             #+#    #+#             */
/*   Updated: 2020/10/08 13:47:12 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		convert(unsigned char *str, unsigned int size)
{
	str[0] = (unsigned char)(size);
	str[1] = (unsigned char)(size >> 8);
	str[2] = (unsigned char)(size >> 16);
	str[3] = (unsigned char)(size >> 24);
}

static void		head(t_cub *cub, unsigned int size_bmp, int fd)
{
	unsigned int	i;
	unsigned char	str[54];

	i = 0;
	while (i < 54)
		str[i++] = (unsigned char)(0);
	str[0] = (unsigned char)('B');
	str[1] = (unsigned char)('M');
	convert(str + 2, size_bmp);
	str[10] = (unsigned char)(54);
	str[14] = (unsigned char)(40);
	convert(str + 18, cub->win.x);
	convert(str + 22, cub->win.y);
	str[26] = (unsigned char)(1);
	str[28] = (unsigned char)(32);
	if (!(write(fd, str, 54)))
		ft_errors(cub, -9);
}

static void		create_bmp_2(t_cub *cub, t_img1 *img, int fd)
{
	int				i;
	int				j;
	unsigned int	color;

	j = cub->win.y - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < cub->win.x)
		{
			color = *(unsigned int*)(img->addr + (j * img->line + i * \
				(img->bits / 8)));
			i++;
			if (!(write(fd, &color, 4)))
				ft_errors(cub, -9);
		}
		j--;
	}
}

void			create_bmp(t_cub *cub)
{
	unsigned int	size_bmp;
	int				fd;

	if ((fd = open("screenshot.bmp", O_CREAT | O_TRUNC | O_WRONLY | O_APPEND,
		0666)) == -1)
		ft_errors(cub, -9);
	size_bmp = 54 + (cub->win.x * cub->win.y * 4);
	head(cub, size_bmp, fd);
	create_bmp_2(cub, &cub->img, fd);
	close(fd);
	ft_errors(cub, 0);
}
