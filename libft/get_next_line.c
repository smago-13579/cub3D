/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:30:27 by smago             #+#    #+#             */
/*   Updated: 2020/08/19 13:08:55 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 10

static char	*ft_strchr2(const char *str, int ch)
{
	char *tmp;

	while (*str != (char)ch && *str != '\0')
	{
		str++;
	}
	if (*str == (char)ch)
	{
		tmp = (char*)str;
		*tmp = '\0';
		str++;
		return ((char*)str);
	}
	return (NULL);
}

static int	clear_gnl(char **string, char **line)
{
	if (*string)
	{
		free(*string);
		*string = NULL;
	}
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	return (-1);
}

static int	check_gnl(int fd, char **line, int *ret)
{
	char c;

	*ret = 0;
	if (line == NULL)
		return (1);
	if ((read(fd, &c, 0)) < 0)
		return (1);
	return (0);
}

static char	*check_string(char **string, char **line)
{
	char *slash;

	slash = NULL;
	if (*string)
	{
		if ((slash = ft_strchr2(*string, '\n')))
		{
			*line = ft_strdup(*string);
			ft_strlcpy(*string, slash, (ft_strlen(slash) + 1));
		}
		else
		{
			*line = ft_strdup(*string);
			free(*string);
			*string = NULL;
		}
	}
	else
	{
		if (!(*line = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		**line = '\0';
	}
	return (slash);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	char		buff[BUFFER_SIZE + 1];
	static char	*string = NULL;
	char		*slash;
	char		*tmp;

	if ((check_gnl(fd, line, &ret)) == 1 || BUFFER_SIZE < 1)
		return (-1);
	slash = check_string(&string, line);
	while (!slash && *line != NULL && (ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((slash = ft_strchr2(buff, '\n')))
		{
			if (!(string = ft_strdup(slash)))
				return (clear_gnl(&string, line));
		}
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
	}
	if (*line == NULL || ret < 0)
		return (clear_gnl(&string, line));
	return (ret || string) ? 1 : 0;
}
