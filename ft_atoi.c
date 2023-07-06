/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggneme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:43:44 by ggneme            #+#    #+#             */
/*   Updated: 2022/10/16 01:33:16 by ggneme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	my_calcul(const char *str, unsigned long int *value, int *i)
{
	while (str[*i] && ('0' <= str[*i] && str[*i] <= '9'))
	{
		*value = *value * 10 + (str[*i] - '0');
		*i = *i + 1;
	}
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	value;
	int					i;
	unsigned long int	max_value;

	value = 0;
	i = 0;
	sign = 1;
	max_value = 9223372036854775807;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i ++;
	if (str[i] == '-')
	{
		sign = -1 * sign;
		i ++;
	}
	else if (str[i] == '+')
		i ++;
	my_calcul(str, &value, &i);
	if (sign > 0 && value > max_value)
		return (-1);
	else if (sign < 0 && value > max_value + 1)
		return (0);
	return (sign * value);
}
