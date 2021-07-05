/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:56:40 by smago             #+#    #+#             */
/*   Updated: 2020/10/12 18:42:38 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_map2(t_cub *cub, char *str)
{
	if (*str == 'R' && *(str + 1) == ' ')
	{
		return (ft_resolution(cub, str));
	}
	else if (*str == 'N' || *str == 'S' || *str == 'W' || *str == 'E' || \
			*str == 'F' || *str == 'C')
	{
		return (ft_textures(cub, str));
	}
	else if (*str != '\0')
		return (-4);
	return (0);
}

static int	parse_map(t_cub *cub)
{
	int		i;
	int		z;
	char	*str;

	i = 0;
	z = 0;
	while ((cub->parse.karta)[i])
	{
		str = (cub->parse.karta)[i];
		str = ft_spaces(str);
		if (*str == '1')
		{
			z = ft_create_map(cub, i);
			if (z == 0)
				return (0);
		}
		else
			z = parse_map2(cub, str);
		i++;
		if (z < 0)
			return (ft_errors(cub, z));
	}
	return (0);
}

static void	ft_lst_error(t_list **head, t_cub *cub)
{
	ft_lstclear(head, free);
	ft_errors(cub, -2);
}

static int	make_map(t_list **head, t_cub *cub)
{
	t_list	*tmp;
	int		i;

	i = -1;
	if (!(cub->parse.karta = ft_calloc(cub->parse.y + 1, sizeof(char *))))
		ft_lst_error(head, cub);
	tmp = *head;
	while (tmp)
	{
		if (!((cub->parse.karta)[++i] = ft_strdup(tmp->content)))
			ft_lst_error(head, cub);
		tmp = tmp->next;
	}
	(cub->parse.karta)[++i] = NULL;
	ft_lstclear(head, free);
	return (parse_map(cub));
}

int			ft_parser(t_cub *cub)
{
	char	*line;
	t_list	*head;
	t_list	*tmp;

	line = NULL;
	head = NULL;
	tmp = NULL;
	while (get_next_line(cub->parse.fd, &line))
	{
		if (!(tmp = ft_lstnew(line)))
			ft_lst_error(&head, cub);
		ft_lstadd_back(&head, tmp);
		if (cub->parse.x <= (int)ft_strlen(line))
			cub->parse.x = (int)ft_strlen(line);
	}
	if (!(tmp = ft_lstnew(line)))
		ft_lst_error(&head, cub);
	ft_lstadd_back(&head, tmp);
	if (cub->parse.x <= (int)ft_strlen(line))
		cub->parse.x = (int)ft_strlen(line);
	cub->parse.y = ft_lstsize(head);
	return (make_map(&head, cub));
}
