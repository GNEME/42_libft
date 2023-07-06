/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:54:02 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/19 22:07:19 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*maillon;
	t_list	*curs;

	list = 0;
	(void)(*del);
	if (ft_lstsize(lst) > 0)
	{
		curs = lst->next;
		if ((*f))
		{
			list = ft_lstnew((*f)(lst->content));
			while (curs)
			{
				maillon = ft_lstnew((*f)(curs->content));
				if (maillon)
					ft_lstadd_back(&list, maillon);
				else
					return (0);
				curs = curs->next;
			}
		}
	}
	return (list);
}
