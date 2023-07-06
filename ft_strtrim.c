/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:45:10 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/27 14:30:13 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

static	int	my_len(char const *s1, char const *set,
	int	*i, int	*nbr)
{
	int	j;

	while (s1[*i] && ft_is_in(set, s1[*i]))
	{
		*nbr = *nbr + 1;
		*i = *i + 1;
	}
	j = *i;
	while (s1[*i])
		*i = *i + 1;
	*i = *i - 1;
	while (*i >= 0 && ft_is_in(set, s1[*i]))
	{
		*nbr = *nbr + 1;
		*i = *i - 1;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		nbr;
	int		i;
	int		j;
	char	*string;

	i = 0;
	nbr = 0;
	if (!s1 || !set)
		return (0);
	j = my_len(s1, set, &i, &nbr);
	if ((size_t)j == ft_strlen(s1))
		string = malloc(sizeof(char));
	else
		string = malloc((ft_strlen(s1) - nbr + 1) * sizeof(char));
	if (string)
	{
		nbr = 0;
		while (j <= i)
			string[nbr++] = s1[j++];
		string[nbr] = '\0';
	}
	return (string);
}
