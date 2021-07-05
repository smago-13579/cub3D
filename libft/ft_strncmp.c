/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 15:19:02 by smago             #+#    #+#             */
/*   Updated: 2020/10/06 21:24:30 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	if (n == 0)
		return (0);
	while (n-- > 0 && *s1 == *s2)
	{
		s1++;
		s2++;
		if (n == 0)
			return (0);
	}
	if (!ft_isascii(*s1) || !ft_isascii(*s2))
		return (1);
	i = *s1 - *s2;
	return (i);
}
