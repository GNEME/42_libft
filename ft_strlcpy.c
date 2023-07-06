/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:12:49 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/27 14:22:53 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	n;

	n = 0;
	if (size > 0)
	{
		while (src[n] != '\0' && n < size - 1)
		{
			dest[n] = src[n];
			n ++;
		}
		dest[n] = '\0';
	}
	return (ft_strlen(src));
}
