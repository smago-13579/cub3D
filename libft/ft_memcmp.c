/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:59:24 by smago             #+#    #+#             */
/*   Updated: 2020/05/03 22:12:34 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int i;

	while (n > 0)
	{
		if (*(unsigned char*)str1 == *(unsigned char*)str2)
		{
			str1++;
			str2++;
		}
		else
		{
			i = *(unsigned char*)str1 - *(unsigned char*)str2;
			return (i);
		}
		n--;
	}
	return (0);
}
