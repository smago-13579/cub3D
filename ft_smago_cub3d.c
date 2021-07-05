/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smago_cub3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:25:25 by smago             #+#    #+#             */
/*   Updated: 2020/10/15 17:45:23 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	init_param3(t_cub *cub)
{
	t_tex		tex;
	t_tex_ns	tex_ns;
	int			i;

	i = 0;
	tex.spr_i = 0;
	tex.i[0] = 0;
	tex.i[1] = 0;
	tex.ceil = 0;
	tex.floor = 0;
	tex.index = 0;
	tex.offset = 0;
	while (i < 5)
	{
		tex_ns.ptr[i] = NULL;
		tex_ns.adr[i] = NULL;
		tex_ns.width[i] = 0;
		tex_ns.height[i] = 0;
		tex_ns.bits[i] = 0;
		tex_ns.line[i] = 0;
		tex_ns.endian[i] = 0;
		i++;
	}
	cub->tex = tex;
	cub->tex_ns = tex_ns;
}

static	void	init_param2(t_cub *cub)
{
	t_player	player;
	t_img1		img;
	t_ray		ray;

	player.x = 0;
	player.y = 0;
	player.a = 0;
	player.fov = M_PI / 3.5;
	img.ptr = NULL;
	img.addr = NULL;
	img.bits = 0;
	img.line = 0;
	img.endian = 0;
	img.x = 0;
	img.y = 0;
	ray.len = 0;
	ray.height = 0;
	cub->player = player;
	cub->img = img;
	cub->ray = ray;
	cub->spr = NULL;
	init_param3(cub);
}

static	void	init_param(t_cub *cub)
{
	t_mlx	mlx;
	t_win	win;
	t_parse	parse;
	t_map	map;

	mlx.ptr = NULL;
	win.ptr = NULL;
	win.x = 0;
	win.y = 0;
	parse.fd = 0;
	parse.karta = NULL;
	parse.x = 0;
	parse.y = 0;
	map.maze = NULL;
	map.x = 0;
	map.y = 0;
	cub->depth = NULL;
	cub->mlx = mlx;
	cub->win = win;
	cub->parse = parse;
	cub->map = map;
	init_param2(cub);
}

static void		start_cub(char *str, t_cub *cub, int i)
{
	cub->mlx.ptr = mlx_init();
	if ((cub->parse.fd = open(str, O_RDONLY)) < 0)
		ft_errors(cub, -1);
	if (ft_strncmp(str + ft_strlen(str) - 4, ".cub", 4))
		ft_errors(cub, -5);
	ft_parser(cub);
	if (!(cub->depth = ft_calloc(cub->win.x, sizeof(double))))
		ft_errors(cub, -2);
	ft_screen(cub, i);
}

int				main(int argc, char **argv)
{
	t_cub	cub;

	init_param(&cub);
	if (argc == 2)
	{
		start_cub(argv[1], &cub, 1);
		mlx_put_image_to_window(cub.mlx.ptr, cub.win.ptr, cub.img.ptr, 0, 0);
		mlx_hook(cub.win.ptr, 2, 1L << 0, ft_events, &cub);
		mlx_hook(cub.win.ptr, 17, 1L << 17, ft_close, &cub);
		mlx_loop(cub.mlx.ptr);
	}
	else if (argc == 3)
	{
		start_cub(argv[1], &cub, 0);
		if (ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) != 0 \
				|| ft_strlen(argv[2]) != 6)
			ft_errors(&cub, -7);
		create_bmp(&cub);
	}
	else
		ft_errors(&cub, -6);
	return (0);
}
