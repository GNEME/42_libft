/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:02:16 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/27 17:46:25 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	char			*string;

	if (!s)
		return (0);
	i = 0;
	string = ft_strdup(s);
	if (string)
	{
		while (s[i])
		{
			string[i] = (*f)(i, s[i]);
			i ++;
		}
	}
	return (string);
}
