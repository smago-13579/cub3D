/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 19:57:08 by smago             #+#    #+#             */
/*   Updated: 2020/05/05 22:06:42 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t n)
{
	unsigned char *str;

	str = (unsigned char*)malloc(nmemb * n);
	if (!str)
		return (NULL);
	ft_bzero(str, nmemb * n);
	return ((void *)str);
}
