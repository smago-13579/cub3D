/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:44:01 by smago             #+#    #+#             */
/*   Updated: 2020/05/18 16:41:09 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t len;
	size_t i;

	len = ft_strlen(dest);
	i = len;
	while (src[len - i] != '\0' && (len + 1) < n)
	{
		dest[len] = src[len - i];
		len++;
	}
	if (i >= n)
	{
		return (n + ft_strlen(src));
	}
	dest[len] = '\0';
	return (i + ft_strlen(src));
}
