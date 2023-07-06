/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:56:51 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/10 22:05:20 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (dest)
		ft_strlcpy(dest, s1, ft_strlen(s1) + 1);
	return (dest);
}
