# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smago <smago@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/05 15:05:44 by smago             #+#    #+#              #
#    Updated: 2020/10/15 23:02:42 by smago            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBDR = libft/

DRLIBFT_A = libft/libft.a

LIBMLXDR = minilibx_mms/

DRLIBMLX = minilibx_mms/libmlx.a

SRCS = ft_smago_cub3d.c ft_bmp.c ft_create_map.c ft_create_sprites.c \
		ft_create_trgb.c ft_draw_line.c ft_errors.c ft_events.c \
		ft_find_sprites.c ft_my_mlx_pixel_put.c ft_parser.c \
		ft_player_direction.c ft_player_position.c ft_resolution.c \
		ft_screen.c ft_spaces.c ft_textures.c

OBJECTS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

FLAG1 = -lm -lX11 -lXext

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS) cub3d.h $(DRLIBFT_A)
	make -C $(LIBMLXDR)
	gcc $(FLAGS) $(OBJECTS) $(DRLIBFT_A) $(DRLIBMLX) $(FLAG1) -o $@

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

$(DRLIBFT_A): libft/*.c libft/libft.h
	make -C $(LIBDR)

clean:
	make -C $(LIBDR) clean
	make -C $(LIBMLXDR) clean
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	rm -f $(DRLIBFT_A)

re: fclean all
