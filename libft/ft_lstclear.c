/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smago <smago@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 22:57:52 by smago             #+#    #+#             */
/*   Updated: 2020/05/21 00:19:09 by smago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;
	t_list *pro;

	pro = *lst;
	if (lst && *lst)
	{
		while (pro)
		{
			tmp = pro->next;
			ft_lstdelone(pro, del);
			pro = tmp;
		}
		*lst = NULL;
	}
}
