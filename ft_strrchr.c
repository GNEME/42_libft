/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:40:21 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/19 22:15:06 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		letter;
	int		i;
	char	*p;

	p = (char *)s;
	i = 0;
	while (*p)
	{
		i ++;
		p ++;
	}
	while (i >= 0)
	{
		letter = *p;
		if ((char)c == letter)
			return (p);
		if (i > 0)
			p --;
		i --;
	}
	if (*p == '\0' && c == '\0')
		return (p);
	return (0);
}
