/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:45:24 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/24 01:38:55 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		letter;
	char	*p;

	p = (char *)s;
	while (*p)
	{
		letter = *p;
		if ((char)c == letter)
			return (p);
		p++;
	}
	if (*p == '\0' && c == '\0')
		return (p);
	return ((char *)0);
}
