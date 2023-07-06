/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:00:41 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/27 14:35:20 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*string;
	size_t		s1_len;
	size_t		s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	string = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (string)
	{
		ft_strlcpy(string, s1, s1_len + 1);
		ft_strlcat(string, s2, s1_len + s2_len + 1);
	}
	return (string);
}
