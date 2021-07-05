/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 19:14:58 by smago             #+#    #+#             */
/*   Updated: 2020/10/15 23:39:56 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_floor_ceil(unsigned int *color, char *str)
{
	int r;
	int g;
	int b;

	str++;
	r = ft_atoi(str);
	str = ft_spaces_atoi(str);
	if (*str != ',')
		return (-4);
	str++;
	g = ft_atoi(str);
	str = ft_spaces_atoi(str);
	if (*str != ',')
		return (-4);
	str++;
	b = ft_atoi(str);
	str = ft_spaces_atoi(str);
	if (*str != '\0' || r > 255 || g > 255 || b > 255 || \
			r < 0 || g < 0 || b < 0)
		return (-4);
	*color = ft_create_trgb(0, r, g, b);
	return (0);
}

static int		ft_addr_from_image(t_cub *cub, t_tex_ns *tex_ns, \
									char *image, int side)
{
	tex_ns->ptr[side] = mlx_xpm_file_to_image(cub->mlx.ptr, image, \
	&(tex_ns->width[side]), &(tex_ns->height[side]));
	free(image);
	if (tex_ns->ptr[side] == NULL)
		return (-3);
	tex_ns->adr[side] = mlx_get_data_addr(tex_ns->ptr[side], \
	&(tex_ns->bits[side]), &(tex_ns->line[side]), &(tex_ns->endian[side]));
	return (0);
}

static int		ft_textures_nswe(t_cub *cub, t_tex_ns *tex_ns, \
									char *str, int side)
{
	char	*image;
	int		fd;

	if (tex_ns->adr[side] != NULL)
		return (-4);
	str += 2;
	if (!(image = ft_strtrim(str, " ")))
		return (-2);
	if (ft_strncmp(image + ft_strlen(image) - 4, ".xpm", 4))
	{
		free(image);
		return (-8);
	}
	if ((fd = open(image, O_RDONLY)) < 0)
	{
		free(image);
		return (-1);
	}
	close(fd);
	return (ft_addr_from_image(cub, tex_ns, image, side));
}

static int		ft_textures2(t_cub *cub, char *str)
{
	int i;

	if (*str == 'F' && *(str + 1) == ' ')
	{
		if (cub->tex.i[0] != 0)
			return (-4);
		i = ft_floor_ceil(&cub->tex.floor, str);
		cub->tex.i[0] = 1;
	}
	else if (*str == 'C' && *(str + 1) == ' ')
	{
		if (cub->tex.i[1] != 0)
			return (-4);
		i = ft_floor_ceil(&cub->tex.ceil, str);
		cub->tex.i[1] = 1;
	}
	else
		return (-4);
	return (i);
}

int				ft_textures(t_cub *cub, char *str)
{
	int		i;

	if (*str == 'N' && *(str + 1) == 'O' && *(str + 2) == ' ')
		i = ft_textures_nswe(cub, &(cub->tex_ns), str, 0);
	else if (*str == 'S' && *(str + 1) == 'O' && *(str + 2) == ' ')
		i = ft_textures_nswe(cub, &(cub->tex_ns), str, 1);
	else if (*str == 'W' && *(str + 1) == 'E' && *(str + 2) == ' ')
		i = ft_textures_nswe(cub, &(cub->tex_ns), str, 2);
	else if (*str == 'E' && *(str + 1) == 'A' && *(str + 2) == ' ')
		i = ft_textures_nswe(cub, &(cub->tex_ns), str, 3);
	else if (*str == 'S' && *(str + 1) == ' ')
		i = ft_textures_nswe(cub, &(cub->tex_ns), str, 4);
	else if (*str == 'F' || *str == 'C')
		i = ft_textures2(cub, str);
	else
		return (-4);
	return (i);
}
