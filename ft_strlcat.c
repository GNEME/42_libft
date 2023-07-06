/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:14:56 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/27 17:15:35 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	i;
	size_t	len;

	if (size == 0 && !dest)
		return (ft_strlen(src));
	i = ft_strlen(dest);
	len = i;
	n = 0;
	if (size <= i)
		return (size + ft_strlen(src));
	while (src[n] != '\0' && i < size - 1)
		dest[i++] = src[n++];
	dest[i] = '\0';
	return (len + ft_strlen(src));
}
