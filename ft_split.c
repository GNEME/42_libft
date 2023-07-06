/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 04:49:35 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/24 05:33:16 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_my_len(char const *s, char c)
{
	int	nbr;
	int	i;

	nbr = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			if (s[i - 1] != c)
				nbr ++;
		i ++;
	}
	return (nbr);
}

static int	my_alloc(char *p, char c, char **strings)
{
	char	*start;
	char	*end;
	int		len;
	int		i;

	i = 0;
	end = p;
	while (*end)
	{
		start = end;
		len = 1;
		while (*end && *end != c && len++)
			end ++;
		while (*end && *end == c)
			end ++;
		strings[i++] = malloc(len * sizeof(char));
		if (!strings[i - 1])
		{
			while (--i >= 0)
				free(strings[i]);
			free(strings);
			return (0);
		}
	}
	return (1);
}

static void	my_copie(char *p, char c, char **strings, int strings_len)
{
	int		i;
	int		j;
	char	*index;

	i = 0;
	index = p;
	while (i < strings_len - 1)
	{
		j = 0;
		while (*index && *index != c)
		{
			strings[i][j++] = *index;
			index ++;
		}
		strings[i][j] = '\0';
		while (*index && *index == c)
			index ++;
		i ++;
	}
	strings[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	char	*p;
	char	set[2];
	int		strings_len;

	set[0] = c;
	set[1] = '\0';
	p = ft_strtrim(s, set);
	if (!p)
		return ((void *)0);
	if (!*p)
		strings_len = 1;
	else
		strings_len = ft_my_len(p, c) + 1;
	strings = malloc(strings_len * sizeof(char *));
	if (strings)
	{
		if (my_alloc(p, c, strings))
			my_copie(p, c, strings, strings_len);
		else
			strings = 0;
	}
	free(p);
	return (strings);
}
