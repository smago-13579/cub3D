/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:21:45 by smago             #+#    #+#             */
/*   Updated: 2020/05/05 14:41:19 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)ch)
		{
			return ((char*)&str[i]);
		}
		i--;
	}
	return (NULL);
}
