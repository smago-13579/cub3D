/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 19:25:11 by smago             #+#    #+#             */
/*   Updated: 2020/05/04 20:03:47 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	while (*str != (char)ch && *str != '\0')
	{
		str++;
	}
	if (*str == (char)ch)
	{
		return ((char*)str);
	}
	return (NULL);
}
