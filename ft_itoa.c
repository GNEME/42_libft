/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:23:09 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/13 01:33:05 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	n_len(unsigned int n)
{
	if (0 <= n && n <= 9)
		return (1);
	return (n_len(n / 10) + n_len(n % 10));
}

static void	n_char(unsigned int n, char **string)
{
	if (0 <= n && n <= 9)
	{
		*(*string) = (n + '0');
		*string = *string + 1;
	}
	else
	{
		n_char(n / 10, string);
		n_char(n % 10, string);
	}
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	unsigned int	i;
	char			*string;
	char			*p;

	i = 0;
	if (n < 0)
		len = n_len(-n) + 2;
	else
		len = n_len(n) + 1;
	string = malloc(len * sizeof(char));
	p = string;
	if (string)
	{
		if (n < 0)
		{
			*p = '-';
			p ++;
			n_char(-n, &p);
		}
		else
			n_char(n, &p);
		*p = '\0';
	}
	return (string);
}
