/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 00:12:39 by smago             #+#    #+#             */
/*   Updated: 2020/05/06 00:56:09 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*str2;

	len = ft_strlen(str);
	if (!(str2 = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str2[len] = '\0';
	while (len-- > 0)
	{
		str2[len] = str[len];
	}
	return (str2);
}
