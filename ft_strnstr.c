/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:45:22 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/27 14:36:05 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_my_strchr(const char *s, int c, size_t *i)
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
		*i = *i + 1;
	}
	if (*p == '\0' && c == '\0')
		return (p);
	return (0);
}

static size_t	nbr_ocur(const char *s, int c)
{
	int			letter;
	char		*p;
	size_t		nbr;

	p = (char *)s;
	nbr = 0;
	while (*p)
	{
		letter = *p;
		if ((char)c == letter)
			nbr ++;
		p++;
	}
	return (nbr);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		len_needle;
	char		*p;

	if (!haystack && len == 0)
		return (0);
	i = 0;
	j = nbr_ocur(haystack, needle[0]);
	len_needle = ft_strlen(needle);
	p = ft_my_strchr(haystack, needle[0], &i);
	while (j-- && i <= len - 1)
	{
		if (*haystack && *needle)
			if (ft_strncmp(p, needle, len_needle) == 0)
				if (i + len_needle <= len)
					return (p);
		++i;
		p = ft_my_strchr(p + 1, needle[0], &i);
	}
	if (!*needle)
		return ((char *)haystack);
	return (0);
}
