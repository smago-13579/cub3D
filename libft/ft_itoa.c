/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 14:56:31 by smago             #+#    #+#             */
/*   Updated: 2020/05/12 15:31:58 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	negative_num(char *str, int n)
{
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = -(n % 1000000000);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[0] = '0';
	return (n);
}

static int	num_char(int n)
{
	int i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = num_char(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
	{
		return (NULL);
	}
	str[i--] = '\0';
	if (n <= 0)
	{
		n = negative_num(str, n);
	}
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
