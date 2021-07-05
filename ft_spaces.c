/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:34:19 by smago             #+#    #+#             */
/*   Updated: 2020/10/15 23:26:53 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_spaces(char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' || \
			*str == '\r' || *str == '\v' || *str == '\f')
	{
		str++;
	}
	return (str);
}

char	*ft_spaces_atoi(char *str)
{
	str = ft_spaces(str);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	str = ft_spaces(str);
	return (str);
}
