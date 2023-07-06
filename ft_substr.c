/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:28:55 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/27 14:36:28 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*string;
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		string = malloc(sizeof(char));
		string[0] = '\0';
		return (string);
	}
	while (i < len && s[start + i])
		i ++;
	i ++;
	string = malloc(i * sizeof(char));
	if (string)
		ft_strlcpy(string, &s[start], i);
	return (string);
}
