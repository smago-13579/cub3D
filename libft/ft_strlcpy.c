/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 14:08:50 by smago             #+#    #+#             */
/*   Updated: 2020/05/18 16:39:59 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t len;

	len = ft_strlen(src);
	if (n == 0)
		return (len);
	while ((--n > 0) && (*src != '\0'))
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (len);
}
