/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 12:01:51 by smago             #+#    #+#             */
/*   Updated: 2020/05/12 15:37:46 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lasttrim(char const *s1, char const *set, int z)
{
	size_t	i;
	int		len;

	i = 0;
	len = ft_strlen(s1) - 1;
	while (len > z && i < ft_strlen(set))
	{
		if (set[i] == s1[len])
		{
			i = 0;
			len--;
		}
		else
			i++;
	}
	return (len);
}

static int	starttrim(char const *s1, char const *set)
{
	size_t	i;
	int		z;

	i = 0;
	z = 0;
	while (s1[z] != '\0' && i < ft_strlen(set))
	{
		if (set[i] == s1[z])
		{
			i = 0;
			z++;
		}
		else
			i++;
	}
	return (z);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		z;
	int		len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	z = starttrim(s1, set);
	len = lasttrim(s1, set, z);
	if (!(str = ft_calloc((len - z + 2), sizeof(char))))
		return (NULL);
	while (z <= len)
	{
		str[i++] = s1[z++];
	}
	return (str);
}
