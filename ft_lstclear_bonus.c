/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:32:42 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/19 22:06:37 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;

	if (!lst || !(*del))
		return ;
	p = *lst;
	if (p)
	{
		while ((*lst)->next)
		{
			(*lst) = (*lst)->next;
			(*del)(p->content);
			free(p);
			p = *lst;
		}
		(*del)(p->content);
		free(p);
	}
	*lst = 0;
}
