/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:44:15 by ybenlafk          #+#    #+#             */
/*   Updated: 2022/12/29 14:44:40 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	scapes(char *str, int *i)
{
	while (str[*i] == '\t' || str[*i] == '\n'
		|| str[*i] == '\v' || str[*i] == '\f'
		|| str[*i] == '\r' || str[*i] == ' ')
		(*i)++;
}

pid_t	ft_atoi(char *str)
{
	pid_t	res;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	res = 0;
	scapes(str, &i);
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
		res = res * 10 + str[i++] - '0';
	return (res * sign);
}

void	putnbr(pid_t number)
{
	if (number > 9)
		putnbr(number / 10);
	write(1, &"0123456789"[number % 10], 1);
}

void	putstrr(char *s)
{
	while (*s)
		write(1, &*s++, 1);
}