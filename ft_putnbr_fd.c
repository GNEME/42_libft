/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:01:11 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/13 14:05:29 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_put(unsigned int nbr, int fd)
{
	char	c;

	if (0 <= nbr && nbr <= 9)
	{
		c = nbr + '0';
		write(fd, &c, 1);
	}
	else
	{
		my_put(nbr / 10, fd);
		my_put(nbr % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		my_put(-n, fd);
	}
	else
		my_put(n, fd);
}
