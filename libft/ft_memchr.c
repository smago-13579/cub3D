/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:14:47 by smago             #+#    #+#             */
/*   Updated: 2020/05/03 21:45:47 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int ch, size_t n)
{
	unsigned char *str;

	str = (unsigned char*)src;
	while (n > 0)
	{
		if (*str == (unsigned char)ch)
		{
			return ((void*)str);
		}
		str++;
		n--;
	}
	return (NULL);
}
