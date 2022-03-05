/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hadd <ael-hadd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:09:07 by ael-hadd          #+#    #+#             */
/*   Updated: 2022/03/05 12:53:55 by ael-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h" 

int	ft_atoi(const char *nptr)
{
	int				i;
	unsigned long	intv;
	int				sign;

	i = 0;
	intv = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\n' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
		intv = intv * 10 + nptr[i++] - 48;
	if (intv > 4294967295)
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	return (intv * sign);
}
