/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:03:13 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/27 17:26:41 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	letter;
	size_t			i;

	i = 0;
	while (i < n)
	{
		letter = ((unsigned char *)s)[i];
		if ((unsigned char)c == letter)
			return (&((unsigned char *)s)[i]);
		i++;
	}
	return (0);
}
