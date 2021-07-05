/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:48:35 by smago             #+#    #+#             */
/*   Updated: 2020/05/17 16:12:01 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t i;

	i = 0;
	if (*little == '\0')
		return ((char*)big);
	while (n-- > 0 && *big)
	{
		if (little[i] == big[i])
		{
			i++;
			if (little[i] == '\0')
				return ((char*)big);
		}
		else
		{
			big++;
			n = n + i;
			i = 0;
		}
	}
	return (NULL);
}
