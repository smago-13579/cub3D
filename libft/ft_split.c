/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:04:42 by smago             #+#    #+#             */
/*   Updated: 2020/05/12 15:29:57 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*free_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int		num_sym(char const *s, char c)
{
	int i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

static int		num_str(char const *s, char c)
{
	int num;

	num = 0;
	if (*s != c && *s != '\0')
	{
		s++;
		num++;
	}
	while (*s != '\0')
	{
		while (*s == c)
		{
			s++;
			if (*s != c && *s != '\0')
			{
				num++;
			}
		}
		if (*s == '\0')
			return (num);
		s++;
	}
	return (num);
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		num;

	i = 0;
	num = 0;
	if (!s || !(str = (char**)malloc(sizeof(char*) * (num_str(s, c) + 1))))
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			if (!(str[num] = (char*)malloc(sizeof(char) * (num_sym(s, c) + 1))))
				return (free_str(str));
			while (*s != c && *s != '\0')
				str[num][i++] = *s++;
			str[num++][i] = '\0';
			i = 0;
		}
	}
	str[num] = NULL;
	return (str);
}
