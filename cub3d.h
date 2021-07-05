/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 12:46:36 by smago             #+#    #+#             */
/*   Updated: 2020/10/12 18:46:17 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "minilibx_mms/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define STEP 0.15
# define RL 0.01
# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

typedef struct		s_mlx
{
	void			*ptr;
}					t_mlx;

typedef struct		s_win
{
	void			*ptr;
	int				x;
	int				y;
}					t_win;

typedef struct		s_parse
{
	int				fd;
	char			**karta;
	int				x;
	int				y;
}					t_parse;

typedef struct		s_map
{
	char			**maze;
	int				x;
	int				y;
}					t_map;

typedef struct		s_tex
{
	int				spr_i;
	int				i[2];
	unsigned int	floor;
	unsigned int	ceil;
	unsigned int	index;
	double			offset;
}					t_tex;

typedef struct		s_tex_ns
{
	void			*ptr[5];
	char			*adr[5];
	int				width[5];
	int				height[5];
	int				bits[5];
	int				line[5];
	int				endian[5];
}					t_tex_ns;

typedef struct		s_spr
{
	double			x;
	double			y;
	double			a;
	double			d;
}					t_spr;

typedef struct		s_player
{
	double			x;
	double			y;
	double			a;
	double			fov;
}					t_player;

typedef struct		s_img1
{
	void			*ptr;
	char			*addr;
	int				bits;
	int				line;
	int				endian;
	int				x;
	int				y;
}					t_img1;

typedef struct		s_ray
{
	double			len;
	double			height;
}					t_ray;

typedef	struct		s_crd
{
	double			i;
	double			j;
}					t_crd;

typedef struct		s_cub
{
	double			*depth;
	t_mlx			mlx;
	t_win			win;
	t_parse			parse;
	t_img1			img;
	t_map			map;
	t_player		player;
	t_ray			ray;
	t_tex			tex;
	t_tex_ns		tex_ns;
	t_spr			*spr;
}					t_cub;

int					ft_parser(t_cub *cub);
int					ft_events(int key, t_cub *cub);
int					ft_close(t_cub *cub);
char				*ft_spaces(char *str);
char				*ft_spaces_atoi(char *str);
int					ft_resolution(t_cub *cub, char *str);
int					ft_textures(t_cub *cub, char *str);
int					ft_create_map(t_cub *cub, int i);
int					ft_create_sprites(t_map *map, t_cub *cub, int i);
int					ft_screen(t_cub *cub, int i);
void				player_position(t_cub *cub, int key);
void				ray_pixel_put(t_cub *cub, t_player *player, t_ray *ray);
void				ft_find_sprites(t_cub *cub, t_player *player, \
									t_spr *spr, int i);
void				draw_line(t_cub *cub, int start, double offset);
void				draw_pixels(t_img1 *img, int i, int j, int color);
int					p_dir(t_map *map, int x, int y);
int					ft_create_trgb(int t, int r, int g, int b);
int					ft_errors(t_cub *cub, int i);
void				create_bmp(t_cub *cub);

#endif
